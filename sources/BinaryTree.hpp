#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

namespace ariel {
    template<typename T>
    class BinaryTree {
        class Node {
            public:
            Node(T v):value(v) {}
            T value;
            Node* parent = nullptr;
            Node* right = nullptr;
            Node* left = nullptr;
        };
        Node* head;
        public:
        BinaryTree() {head = nullptr;}
        ~BinaryTree() {
            /* The form of postorder() implementation is by fully inserting all the tree nodes into a stack
                before retrieving any of them so the tree can be changed while running, In addition, since 
                postorder is leftChild->rightChild->parent so childs memory released before the parent. */
            for (auto it=(*this).begin_postorder(); it!=(*this).end_postorder(); ++it) {delete it.node;}
        }
        
        BinaryTree& add_root(T v) {
            if (head!=nullptr) {
                head->value = v;
                return *this;
            }
            Node& temp = *(new Node(v));
            head = &temp;
            return *this;
        }

        BinaryTree& add_left(T v, T v2) {
            if (head==nullptr) {throw invalid_argument("null root!");}
            /* The form of postorder() implementation is by fully inserting all the tree nodes
               into a stack before retrieving any of them so the tree can be changed while running */
            for (auto it=(*this).begin_postorder(); it!=(*this).end_postorder(); ++it) {
                if ((*it)==v) {
                    if (it.node->left==nullptr) {
                        Node& temp = *(new Node(v2));
                        temp.parent = it.node;
                        it.node->left = &temp;
                    } else {it.node->left->value = v2;}
                    return *this;
                }
            }
            ostringstream ostr;
            ostr << "could not find " << v;
            throw invalid_argument(ostr.str());
        }

        BinaryTree& add_right(T v, T v2) {
            if (head==nullptr) {throw invalid_argument("null head!");}
            /* The form of postorder() implementation is by fully inserting all the tree nodes
               into a stack before retrieving any of them so the tree can be changed while running */
            for (auto it=(*this).begin_postorder(); it!=(*this).end_postorder(); ++it) {
                if ((*it)==v) {
                    if (it.node->right==nullptr) {
                        Node& temp = *(new Node(v2));
                        temp.parent = it.node;
                        it.node->right = &temp;
                    } else {it.node->right->value = v2;}
                    return *this;
                }
            }
            ostringstream ostr;
            ostr << "could not find " << v;
            throw invalid_argument(ostr.str());
        }

        /* credit: https://www.geeksforgeeks.org/iterative-preorder-traversal */
        class iterator_preorder { // parent->left->right
            public:
            Node* node;
            stack<Node*> stack;
            iterator_preorder(Node* head):node(head){
                if (node->right) {stack.push(node->right);}
                if (node->left) {stack.push(node->left);}
            };
            iterator_preorder():node(nullptr){ };
            iterator_preorder& operator++() {
                if (stack.empty()) {
                    node = nullptr;
                    return *this;
                }
                node = stack.top();
                stack.pop();
                if (node->right) {stack.push(node->right);}
                if (node->left) {stack.push(node->left);}
                return *this;
            }
            iterator_preorder& operator+(int num) {
                for (int i = 0; i < num; i++) {this->operator++();}
                return *this;
            }
            int size() {return string(node->value).size();}
            bool operator!=(const iterator_preorder& other) {return node != other.node;}
            iterator_preorder* operator->() {return this;}
            T& operator*() {return node->value;}
        };

        /* credit: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion */
        class iterator_inorder { // left->parent->right
            public:
            Node* node;
            stack<Node*> stack;
            iterator_inorder(Node* head):node(head){
                while (node != nullptr) {
                    stack.push(node);
                    node = node->left;
                }
                node = stack.top();
                stack.pop();
            };
            iterator_inorder():node(nullptr){ };
            iterator_inorder& operator++(){
                node = node->right;
                if (stack.empty()&node==nullptr) {
                    node = nullptr;
                    return *this;
                }
                while (node != nullptr) {
                    stack.push(node);
                    node = node->left;
                }
                node = stack.top();
                stack.pop();
                return *this;
            }
            iterator_inorder& operator+(int num) {
                for (int i = 0; i < num; i++) {this->operator++();}
                return *this;
            }
            int size() {return string(node->value).size();}
            bool operator!=(const iterator_inorder& other) {return node != other.node;}
            iterator_inorder* operator->() {return this;}
            T& operator*() {return node->value;}
        };

        /* credit: https://www.geeksforgeeks.org/iterative-postorder-traversal */
        class iterator_postorder { // left->right->parent
            public:
            Node* node;
            stack<Node*> stack1, stack2;
            iterator_postorder(Node* head):node(head){
                stack1.push(head);
                while (!stack1.empty()) {
                    node = stack1.top();
                    stack1.pop();
                    stack2.push(node);
                    if (node->left) stack1.push(node->left);
                    if (node->right) stack1.push(node->right);
                }
                node = stack2.top();
                stack2.pop();
            }
            iterator_postorder():node(nullptr){ };
            iterator_postorder& operator++(){
                if (stack2.empty()) {
                    node = nullptr;
                    return *this;
                }
                node = stack2.top();
                stack2.pop();
                return *this;
            }
            iterator_postorder& operator+(int num) {
                for (int i = 0; i < num; i++) {this->operator++();}
                return *this;
            }
            int size() {return string(node->value).size();}
            bool operator!=(const iterator_postorder& other) {return node != other.node;}
            iterator_postorder* operator->() {return this;}
            T& operator*() {return node->value;}
        };

        iterator_inorder begin() {return iterator_inorder(head);}

        iterator_inorder end() {return iterator_inorder();}

        iterator_preorder begin_preorder() {return iterator_preorder(head);}

        iterator_preorder end_preorder() {return iterator_preorder();}

        iterator_inorder begin_inorder() {return iterator_inorder(head);}

        iterator_inorder end_inorder() {return iterator_inorder();}

        iterator_postorder begin_postorder() {return iterator_postorder(head);}
        
        iterator_postorder end_postorder() {return iterator_postorder();}
        

        /* source: https://www.geeksforgeeks.org/print-level-order-traversal-line-line */
        ostream& printLevelOrder(ostream& os) const {
            int counter = 0;
            Node* node = head;
            while(node->left) {
                 node = node->left;
                 counter++;
            }
            counter*=2;
            Node *root = head;
            /* Base Case */
            if (root == NULL) return os;
            /* Create an empty queue for level order traversal */
            queue<Node*> q;
            /* Enqueue Root and initialize height */
            q.push(root);
            while (q.empty() == false) {
                for (int i = 0; i < counter; i++) {os << " ";}
                counter--;
                /* nodeCount (queue size) indicates number of nodes at current lelvel. */
                int nodeCount = q.size();
                /* Dequeue all nodes of current level and Enqueue all nodes of next level */
                while (nodeCount > 0) {
                    Node *node = q.front();
                    os << node->value << " ";
                    q.pop();
                    if (node->left != NULL) {q.push(node->left);}
                    if (node->right != NULL) {q.push(node->right);}
                    nodeCount--;
                }
                os << endl;
            }
            return os;
        }

        friend ostream& operator<<(ostream& os, const BinaryTree<T>& b) {return b.printLevelOrder(os);}
    };
}