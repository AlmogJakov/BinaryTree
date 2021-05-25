/**
 * AUTHORS: AlmogJakov
 * 
 * Date: 2021-05
 */

#include "doctest.h"
#include "BinaryTree.hpp"
using namespace ariel;
#include <sstream> // stringstream
#include <string>
using namespace std;

    ///////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// add_root test ////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

TEST_CASE("add_root test") {
    stringstream result;
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1);
    for (int element: tree_of_ints) {result << element;} // this should work like inorder
    CHECK(result.str() == "1");
    result.str("");
    /* Root override scenario */
    tree_of_ints.add_root(2);
    for (int element: tree_of_ints) {result << element;} // this should work like inorder
    CHECK(result.str() == "2");

    result.str("");
    BinaryTree<double> tree_of_doubles;
    tree_of_doubles.add_root(1.5);
    for (double element: tree_of_doubles) {result << element;} // this should work like inorder
    CHECK(result.str() == "1.5");
    result.str("");
    /* Root override scenario */
    tree_of_doubles.add_root(2.6);
    for (double element: tree_of_doubles) {result << element;} // this should work like inorder
    CHECK(result.str() == "2.6");

    result.str("");
    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("root_check");
    for (string element: tree_of_strings) {result << element;} // this should work like inorder
    CHECK(result.str() == "root_check");
    result.str("");
    /* Root override scenario */
    tree_of_strings.add_root("override_check");
    for (string element: tree_of_strings) {result << element;} // this should work like inorder
    CHECK(result.str() == "override_check");
}

    ///////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// add_left test ////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

TEST_CASE("add_left test") {
    BinaryTree<int> tree_of_ints;
    /* should throw (no root) */
    CHECK_THROWS(tree_of_ints.add_left(1, 2););

    stringstream result;
    tree_of_ints.add_root(1);
    tree_of_ints.add_left(1, 2);
    for (int element: tree_of_ints) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "2 1 ");
    result.str("");
    tree_of_ints.add_left(2, 3);
    for (int element: tree_of_ints) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "3 2 1 ");
    result.str("");
    /* Variable override scenario */
    tree_of_ints.add_left(1, -3);
    for (int element: tree_of_ints) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "3 -3 1 ");
    /* No-input-found scenario */
    CHECK_THROWS(tree_of_ints.add_left(20, 1));

    result.str("");
    BinaryTree<double> tree_of_doubles;
    tree_of_doubles.add_root(1.5);
    tree_of_doubles.add_left(1.5, 2.6);
    for (double element: tree_of_doubles) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "2.6 1.5 ");
    result.str("");
    tree_of_doubles.add_left(2.6, 3.7);
    for (double element: tree_of_doubles) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "3.7 2.6 1.5 ");
    result.str("");
    /* Variable override scenario */
    tree_of_doubles.add_left(1.5, -3.7);
    for (double element: tree_of_doubles) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "3.7 -3.7 1.5 ");
    /* No-input-found scenario */
    CHECK_THROWS(tree_of_doubles.add_left(20.2, 1.2));
    
    result.str("");
    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("parent");
    tree_of_strings.add_left("parent", "child");
    for (string element: tree_of_strings) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "child parent ");
    result.str("");
    tree_of_strings.add_left("child", "grandson");
    for (string element: tree_of_strings) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "grandson child parent ");
    result.str("");
    /* Variable override scenario */
    tree_of_strings.add_left("parent", "grandson");
    for (string element: tree_of_strings) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "grandson grandson parent ");
    /* No-input-found scenario */
    CHECK_THROWS(tree_of_strings.add_left("other", "other"));
}

    ////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// add_right test ////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////

TEST_CASE("add_right test") {
    BinaryTree<int> tree_of_ints;
    /* should throw (no root) */
    CHECK_THROWS(tree_of_ints.add_right(1, 2););

    stringstream result;
    tree_of_ints.add_root(1);
    tree_of_ints.add_right(1, 2);
    for (int element: tree_of_ints) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "1 2 ");
    result.str("");
    tree_of_ints.add_right(2, 3);
    for (int element: tree_of_ints) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "1 2 3 ");
    result.str("");
    /* Variable override scenario */
    tree_of_ints.add_right(1, -3);
    for (int element: tree_of_ints) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "1 -3 3 ");
    /* No-input-found scenario */
    CHECK_THROWS(tree_of_ints.add_right(20, 1));

    result.str("");
    BinaryTree<double> tree_of_doubles;
    tree_of_doubles.add_root(1.5);
    tree_of_doubles.add_right(1.5, 2.6);
    for (double element: tree_of_doubles) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "1.5 2.6 ");
    result.str("");
    tree_of_doubles.add_right(2.6, 3.7);
    for (double element: tree_of_doubles) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "1.5 2.6 3.7 ");
    result.str("");
    /* Variable override scenario */
    tree_of_doubles.add_right(1.5, -3.7);
    for (double element: tree_of_doubles) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "1.5 -3.7 3.7 ");
    /* No-input-found scenario */
    CHECK_THROWS(tree_of_doubles.add_right(20.2, 1.2));
    
    result.str("");
    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("parent");
    tree_of_strings.add_right("parent", "child");
    for (string element: tree_of_strings) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "parent child ");
    result.str("");
    tree_of_strings.add_right("child", "grandson");
    for (string element: tree_of_strings) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "parent child grandson ");
    result.str("");
    /* Variable override scenario */
    tree_of_strings.add_right("parent", "grandson");
    for (string element: tree_of_strings) {result << element << " ";} // this should work like inorder
    CHECK(result.str() == "parent grandson grandson ");
    /* No-input-found scenario */
    CHECK_THROWS(tree_of_strings.add_right("other", "other"));
}

    ///////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// preorder test ////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

TEST_CASE("preorder test") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 9)
    .add_left(9, 4)
    .add_right(9, 5)
    .add_right(1, 3)
    .add_left(1, 2);
    stringstream result;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: 1 2 4 5 3 
    CHECK(result.str() == "1 2 4 5 3 ");
    result.str("");

    BinaryTree<double> tree_of_doubles;
    tree_of_doubles.add_root(1.2)
    .add_left(1.2, 9.8)
    .add_left(9.8, 4.5)
    .add_right(9.8, 5.6)
    .add_right(1.2, 3.4)
    .add_left(1.2, 2.3);
    for (auto it=tree_of_doubles.begin_preorder(); it!=tree_of_doubles.end_preorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: 1.2 2.3 4.5 5.6 3.4 
    CHECK(result.str() == "1.2 2.3 4.5 5.6 3.4 ");
    result.str("");

    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("one")
    .add_left("one", "nine")
    .add_left("nine", "four")
    .add_right("nine", "five")
    .add_right("one", "three")
    .add_left("one", "two");
    for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: one two four five three
    CHECK(result.str() == "one two four five three ");
}

    //////////////////////////////////////////////////////////////////////////////
    //////////////////////////////// inorder test ////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

TEST_CASE("inorder test") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 9)
    .add_left(9, 4)
    .add_right(9, 5)
    .add_right(1, 3)
    .add_left(1, 2);
    stringstream result;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: 4 2 5 1 3 
    CHECK(result.str() == "4 2 5 1 3 ");
    result.str("");

    BinaryTree<double> tree_of_doubles;
    tree_of_doubles.add_root(1.2)
    .add_left(1.2, 9.8)
    .add_left(9.8, 4.5)
    .add_right(9.8, 5.6)
    .add_right(1.2, 3.4)
    .add_left(1.2, 2.3);
    for (auto it=tree_of_doubles.begin_inorder(); it!=tree_of_doubles.end_inorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: 4.5 2.3 5.6 1.2 3.4 
    CHECK(result.str() == "4.5 2.3 5.6 1.2 3.4 ");
    result.str("");

    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("one")
    .add_left("one", "nine")
    .add_left("nine", "four")
    .add_right("nine", "five")
    .add_right("one", "three")
    .add_left("one", "two");
    for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: four two five one three 
    CHECK(result.str() == "four two five one three ");
}

    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// postorder test ///////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

TEST_CASE("postorder test") {
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
    .add_left(1, 9)
    .add_left(9, 4)
    .add_right(9, 5)
    .add_right(1, 3)
    .add_left(1, 2);
    stringstream result;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: 4 5 2 3 1 
    CHECK(result.str() == "4 5 2 3 1 ");
    result.str("");

    BinaryTree<double> tree_of_doubles;
    tree_of_doubles.add_root(1.2)
    .add_left(1.2, 9.8)
    .add_left(9.8, 4.5)
    .add_right(9.8, 5.6)
    .add_right(1.2, 3.4)
    .add_left(1.2, 2.3);
    for (auto it=tree_of_doubles.begin_postorder(); it!=tree_of_doubles.end_postorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: 4.5 5.6 2.3 3.4 1.2 
    CHECK(result.str() == "4.5 5.6 2.3 3.4 1.2 ");
    result.str("");

    BinaryTree<string> tree_of_strings;
    tree_of_strings.add_root("one")
    .add_left("one", "nine")
    .add_left("nine", "four")
    .add_right("nine", "five")
    .add_right("one", "three")
    .add_left("one", "two");
    for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
        result << (*it) << " " ;
    }  // prints: four five two three one 
    CHECK(result.str() == "four five two three one ");
}