#pragma once

#include <string>

// Node of a tree, stores a word
struct Node
{
    // Word stored in this node of the tree
    std::string word = "";
	int wordCounter = 0; // Word counter that will store the counter of the words that will occur in the file
    
    // The left branch of the tree
    Node *left = nullptr;
    // The right branch of the tree
    Node *right = nullptr;
};
