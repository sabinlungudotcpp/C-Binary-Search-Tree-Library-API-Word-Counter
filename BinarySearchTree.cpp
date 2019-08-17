#include "BinarySearchTree.h"
#include "Node.h"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
@ Author Name: Sabin Constantin Lungu
@ Date of Last Modification: 26/03/2019 @ 20:53
@ Purpose Of Program: The purpose of this BinarySearchTree.cpp file is to fill in the methods that have been given to us by default with code that is used to build a Binary Search Tree API library.
@ Parameters Used In The Program: "std::string word -> This is used to store the word that is present in the Binary Tree" "root: The root of the tree"
*/


// **Constructors **
BinarySearchTree::BinarySearchTree() // Default constructor called
{
	root = new Node;
}

BinarySearchTree::BinarySearchTree(std::string word) // A constructor to declare the tree data.
{
	this->root = new Node; // Allocate memory on the heap using the new keyword.
	this->root->word = word;
	
	this->root->left = nullptr; // Set the left branch of the tree to null.
	this->root->right = nullptr; // Set the right branch of the tree to empty (null)
}

void copyTwoTrees(Node **tree, Node *tree2) { // A void routine that takes in two node pointers, one for the current tree and one for the new tree.
	if (tree2 == nullptr) { // If this current tree is empty then automatically set the second tree to copy to to empty.
		*tree = nullptr;
	}

	else {
		*tree = new Node; // Otherwise if that is not the case, create a new root pointer node instance.

		(*tree)->word = tree2->word;// Copy the current tree's root word over to the new tree's root word
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;

		copyTwoTrees(&(*tree)->left, tree2->left); // Recursively call the sub-routine to copy over the words from the left branch of the tree to the new tree's left branch.
		copyTwoTrees(&(*tree)->right, tree2->right);
	}
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs) // Default function given to us. It will call the copyTwoTrees helper function to make a copy of the two trees
{
    copyTwoTrees(&this->root, rhs.root);
}


BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words) // Creates a BST from a vector of words.
{
	root = new Node;

	for (int i = 0; i < words.size(); ++i) {
	
		insert(words[i]); // Calls the insert function to add the words to the vector
	}
}

void destroyTree(Node *Node) { // A sub-routine that will destroy the binary search tree by releasing its memory allocated.
	if (Node != nullptr) {
		
		destroyTree(Node->left); // Recurse over the left side of the tree to delete the values.
		destroyTree(Node->right);

		delete Node;
		Node = nullptr; // Good practice to set the nodes to null after being deleted so they can't be reused after.
	}
}

// Destructor
BinarySearchTree::~BinarySearchTree() // A destructor sub-routine represented by the tilde that destroys the node.
{
	destroyTree(root);
}

// **Methods**

Node *insertWord(Node* root, const std::string word) { // A routine that is used to insert a word. Parameters taken: @root: Contains the data in the root of the tree @word -> The word that will get inserted in the tree.
	if (root == nullptr) {

		root = new Node; // Create a new root node
		root->word = word;
		root->wordCounter = 1;
		
		root->left = nullptr;
		root->right = nullptr;
	}

	if (word == root->word) {
		root->wordCounter++;
	}

	if (word < root->word) { // If the word is less than the tree's root word
		root->left = insertWord(root->left, word); // Recursively traverse over the left side of the tree and insert a word.
	}

	else if (word > root->word) { // Do the same for the right hand side of the tree.
		root->right = insertWord(root->right, word);
	}
	
	return root;
}

void BinarySearchTree::insert(std::string word) // A void sub-routine to insert a new word in the tree which will call the helper function above
{
	if (root == nullptr) { // If the root of the tree is empty just return a new node instance
		root = new Node;
		root->word = word;

		root->wordCounter = 1; // Set the counter to 1
		root->left = nullptr;
		root->right = nullptr;
	}

	else {
		insertWord(root, word); // Call the helper function to insert a word
	}
}

bool checkWordInTree(Node *root, std::string word) { // A sub-routine that will check if a word exists in a tree (Lines 133 & 134 Retrieved from search query geeksforgeeks.com C++ Iterative Search)
	while (root != nullptr) { // Loop over the contents of the tree

		if (word > root->word) { // If the word is bigger than the tree's word
			root = root->right; // Traverse over the right hand side to check if a word exists.
		}

		if (word < root->word) { // Do the same for the left side
			root = root->left;
		}

		else if (root->word == word) { // If the word matches with the one in the tree
			return true; // A word has been found
		}
	}

	return false;
}

bool BinarySearchTree::exists(std::string word) const // Boolean sub-routine to check if a word exists
{
	return checkWordInTree(root, word);
}

void wordsInOrder(Node *root, std::string &theWords, int count) { // A sub-routine that sorts the words in order
	
	if (root == nullptr) {
		return;
	}

	if (root->left != nullptr) {
		wordsInOrder(root->left, theWords, count);
	}
		
	if (root->word != "") { // If the root word is not an empty string and the count below is 0
	
		if (count == 0) {
			theWords += root->word + " "; // COncatenate the rood word
		}
		else {
			theWords += root->word + " :" + to_string(root->wordCounter-1) + " \n"; // Add the roots word to the end counter and cast the words to strings using to_string
		}
	}
		
	if (root->right != nullptr) {
		wordsInOrder(root->right, theWords, count);
	    }
	}

std::string BinarySearchTree::inorder() const // Default function to print the words in an inorder fashion.
{
	std::string theWords = "";
	wordsInOrder(this->root, theWords,0);

	if (theWords == "") {
		return std::string("");
	}

	theWords.erase(prev(theWords.end())); // Erase the previous space and the last space from the words
	return theWords;
}

std::string BinarySearchTree::inorderCount() const
{
	std::string theWords = "";
	wordsInOrder(this->root, theWords, 1);

	if (theWords == "") {
		return std::string("");
	}

	theWords.erase(prev(theWords.end()));
	return theWords;
}

void wordsPreOrder(Node *root, std::string &theWords) { // A sub-routine that will print the words in a pre order fashion.
	if (root == nullptr) {
		return;
	}

	if (root->word != "") { // If the word is not equal to an empty string, concatenate the word to the end of an empty string
		theWords += root->word + " ";
	}

	if (root->left != nullptr) { // If the left side of the tree is not empty
		wordsPreOrder(root->left, theWords); // Recursively call the routine to print the words in a pre order fashion on the left side of the tree.
	}

	if (root->right != nullptr) {
		wordsPreOrder(root->right, theWords);
	}
}

std::string BinarySearchTree::preorder() const // Default function to print the words in the tree in a pre order fashion
{
	std::string theWords = "";
	wordsPreOrder(root, theWords);

	if (theWords != "") { // If the words is not an empty string

		theWords.erase(prev(theWords.end())); // Line of code retrieved from Wikipedia (Search Query: "C++ erase words and remove words")
		return theWords;
	}

	else return std::string("");
}

void postOrder(Node *root, std::string &theWords) { // Routine that will print the word in a post order fashion
	if (root == nullptr) {
		return;
	}

	if (root->left != nullptr) {
		postOrder(root->left, theWords);
	}

	if (root->right != nullptr) {
		postOrder(root->right, theWords);
	}

	if (root->word != "") {
		theWords += root->word + " ";
	}
}

std::string BinarySearchTree::postorder() const
{
	std::string theWords = "";

	postOrder(root, theWords);

	if (theWords != "") { // If the words is not an empty string

		theWords.erase(prev(theWords.end())); // Line of code retrieved from Wikipedia (Search Query: "C++ erase words and remove words")
		return theWords;
	}

	else return std::string("");
}
    
// **Operator overloads**
BinarySearchTree& BinarySearchTree::operator+(std::string word) // Default function to perform the + operator overload.
{
	BinarySearchTree *temp = new BinarySearchTree(*this); // Create a temporary tree and insert a word in that tree
	temp->insert(word);

	return *temp;
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs) // Default function to perform the assignment operator overload
{
	root = new Node;
	copyTwoTrees(&this->root, rhs.root);

	return *this;
}
