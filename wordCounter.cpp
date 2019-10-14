#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

// Import header files.
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;

/*
@ Author Name: Sabin Constantin Lungu
@ Date of Last Modification: 26/03/2019 @ 21:07
@ Purpose Of Program: The purpose of this wordCounter.cpp File is to create an application using the BinarySearchTree library API to read in a file, store the words from the file in the BST and print out the number of occurences that each word occurs in the file.
@ Parameters Used In The Program: "&theFile" -> It is used to make reference and get the address of the file that is being read in
*/

BinarySearchTree* readFile(const std::string &theFile) { // A sub-routine to read the test file
	std::string fileLine; // Gets each line from the file.

	vector<string> wordsInVector; // Will store the lines of the file in the vector
	std::ifstream testFile("single_words_test.txt"); // Read in the appropriate test file

	std::string word;

	BinarySearchTree *tree = new BinarySearchTree(); // Create a new binary search tree instance

	if (testFile.is_open()) { // If the file is open loop over the contents

		while (getline(testFile, fileLine)) { // Loop to go over the whole contents of the file
			wordsInVector.push_back(fileLine); 
		}

		testFile.close(); // Close the file to prevent any errors 
	}

	else {
		cout << "Unable to open file, file does not exist" << endl;
	}

	for each (string theStrings in wordsInVector) // For each of the strings in the file insert a new word into the tree.
	{
		tree->insert(theStrings);
	}

	return tree;
}

int main(int argc, char **argv) {

	std::string word; // A string variable to store the words in the Binary Search Tree.

	std::string theFile;

	BinarySearchTree *tree = readFile(theFile);
	string fileStrings = tree->inorderCount();
	
	cout << fileStrings << endl;

	delete tree; // free memory from the tree
	tree = nullptr;

	return 0;
}
