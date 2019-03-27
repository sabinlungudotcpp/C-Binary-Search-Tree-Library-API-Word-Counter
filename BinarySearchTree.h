#pragma once

#include <string>
#include <vector>
#include "Node.h"

class BinarySearchTree
{
public:
	// **Constructors and destructors**
	
	// Creates an empty binary tree
    BinarySearchTree();
    // Creates a binary search tree with an initial word to store
    BinarySearchTree(std::string word);
    // Creates a binary search tree by copying an existing tree
    BinarySearchTree(const BinarySearchTree &rhs);
    // Creates a binary search tree from a collection of existing words
	BinarySearchTree(const std::vector<std::string> &words);
    // Destroys (cleans up) the tree
    ~BinarySearchTree();
    
    // **Methods that can be called on a BinarySearchTree object**
    
    // Adds a word to the tree
    void insert(std::string word);
	// Checks if a word is in the tree
    bool exists(std::string word) const;
    // Creates a string representing the tree in alphabetical order
    std::string inorder() const;
	// Creates a string representing the tree in alphabetical order and prints out the associating count for the word
	std::string inorderCount() const;
    // Creates a string representing the tree in pre-order
    std::string preorder() const;
    // Creates a string representing the tree in post-order
    std::string postorder() const;
    // **Operator overloads**
    
    // Inserts a new word into the binary tree
    BinarySearchTree& operator+(std::string word);

    // Copy assignment operator
    BinarySearchTree& operator=(const BinarySearchTree &rhs);
    
private:
    //instance variables
	Node *root = nullptr; // Pointer to the root Node of the tree
};