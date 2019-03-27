#include <iostream>
#include <string>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char **argv)
{

	// Test 1 - basic constructor
    BinarySearchTree *tree = new BinarySearchTree(); // Create BST object
    string str = tree->inorder();
    if (str != string(""))
        cerr << "ERROR - test 1 failed (basic constructor)" << endl;
    else
        cout << "Test 1 passed (basic constructor)" << endl;
	
    delete tree;
	
    // Test 2 - single value constructor
    tree = new BinarySearchTree("hello");
    str = tree->inorder();

    if (str != string("hello"))
        cerr << "ERROR - test 2 failed (single value constructor)" << endl;
    else
        cout << "Test 2 passed (single value constructor)" << endl;
    delete tree;

    tree = new BinarySearchTree();
    // Test 3 - insertion check
    tree->insert("fish");
    tree->insert("aardvark");
    tree->insert("zeebra");
    tree->insert("dog");
    tree->insert("cat");
    str = tree->inorder();
    
    if (str != string("aardvark cat dog fish zeebra"))
        cerr << "ERROR - test 3 failed (insertion check)" << endl;
    else
        cout << "Test 3 passed (insertion check)" << endl;
    
    // Test 4 - exists check
    
    if (tree->exists("zeebra") && tree->exists("cat") && !tree->exists("bird") && !tree->exists("snake"))
        cout << "Test 4 passed (exists check)" << endl;
    else
        cerr << "ERROR - test 4 failed (exists check)" << endl;
   
   // Test 5 - vector constructor
   vector<string> vec;
   vec.push_back("fish");
   vec.push_back("aardvark");
   vec.push_back("zeebra");
   vec.push_back("dog");
   vec.push_back("cat");
   BinarySearchTree *fromVector = new BinarySearchTree(vec);
   str = fromVector->inorder();
   if (str != string("aardvark cat dog fish zeebra"))
        cerr << "ERROR - test 5 failed (vector constructor)" << endl;
   else
        cout << "Test 5 passed (vector constructor)" << endl;
   delete fromVector;

	
    // Test 6a - copy constructor part 1
    BinarySearchTree *tree2 = new BinarySearchTree(*tree);
    str = tree2->inorder();

    if (str != string("aardvark cat dog fish zeebra"))
        cerr << "ERROR - test 6a failed (copy constructor part 1)" << endl;
    else
        cout << "Test 6a passed (copy constructor part 1)" << endl;

    // Test 6b - copy constructor part 2
    tree2->insert("mouse");
    if (tree->inorder() == tree2->inorder())
        cerr << "ERROR - test 6b failed (copy constructor part 2 - deep copy check)" << endl;
    else
        cout << "Test 6b passed (copy constructor part 2 - deep copy check)" << endl;
    delete tree2;
    tree2 = nullptr;
    
    // Test 7 - preorder print
    str = tree->preorder();
    if (str != string("fish aardvark dog cat zeebra"))
        cerr << "ERROR - test 7 failed (pre-order print)" << endl;
    else
        cout << "Test 7 passed (pre-order print)" << endl;
    
    // Test 8- postorder print
    str = tree->postorder();
    if (str != string("cat dog aardvark zeebra fish"))
        cerr << "ERROR - test 8 failed (post-order print)" << endl;
    else
        cout << "Test 8 passed (post-order print)" << endl;
  
    // Test 9 + operator overload
    BinarySearchTree tree3;
    tree3 = tree3 + "hello";
    tree3 = tree3 + "world";
    str = tree3.inorder();
    if (str != string("hello world"))
    	cerr << "ERROR - test 9 failed (+ operator overload)" << endl;
    else
        cout << "Test 9 passed (+ operator overload)" << endl;
        
    // Test 10 assignment operator overload
    tree3 = *tree;
    tree->insert("hello");
    str = tree3.inorder();
    if (str != string("aardvark cat dog fish zeebra"))
    	cerr << "ERROR - test 10 failed (assignment operator overload)" << endl;
    else
        cout << "Test 10 passed (assignment operator overload)" << endl;    
    delete tree;
    return 0;
}