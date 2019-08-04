# Command Line API - Requirements for Implementing Binary Search Tree
> Constructor to set up the Binary Search Tree Data ✅ 

> A sub-routine that copies data from one tree to another. Implements the method void copyTwoTrees(); ✅ 

> A sub-routine that creates a Binary Search Tree from a vector of words. ✅ 

> A sub-routine that destroys the Binary Search Tree by releasing its memory void destroyTree(); ✅ 

> A sub-routine that inserts a word into the tree Node insertWord(). ✅ 

> A sub-routine that checks if a word is in the Binary Search Tree bool checkWordInTree(). ✅ 

> A sub-routine that prints the words in alphabetical order void wordsInOrder() ✅ 

> A sub-routine that prints the words in a Pre Order fashion void wordsPreOrder() ✅ 

> A Sub-routine that prints the words in a Post Order fashion void wordsPostOrder() ✅ 

> An operator overloading method that performs the + operation.

# C++ Binary-Search-Tree-Library-API-Word-Counter
> This is a C++ Binary Search Tree Library API along with a Word counter application that uses the implemented library.

# C++ Binary Search Tree Library API / Word Counter Application.

> Version 1.0.0

> Author: Sabin Constantin Lungu.

> Project Completion: April 2019

> Purpose of Application: The main purpose of this Binary Search Tree Library is to implement code for 11 separate given methods with the help of creating separate functions to pass 11 given tests in the test.cpp file.

> The Binary Search Tree Library API is then used to build a word counter application. The word count application is used to read in a specific text file, sort the words in alphabetical order, store them all in the Binary Search Tree and count the number of times the word occurs in the file.

# Toolchain Used to build Application: The software used to build this application is the Microsoft Visual Studio Developer Command Prompt Compiler 2017.

# How do I build this application? (Windows 10)

> Start up the Microsoft Visual Studio Developer command prompt 2017.

> Type in the path where the folder is stored in (C: / E: / D: ... )

> Enter the directory of where the project is located using "cd"  (cd Coursework2)

> Type in the MS-DOS shell "nmake build" to build the application using the makefile as an aid.

> After the application/library has been built and after the .obj files have been created, type in "test" in the shell to display the state of the 11 tests that have either passed/failed.

> To access the word counter application after using "nmake build" type in the shell cl wordCounter.cpp BinarySearchTree.cpp to compile the code for the two files into machine code.

> After the .obj file has been created for the wordCounter.cpp file, type in link wordCounter.obj Coursework2.lib to link the object file created to the library.

> After the linking process has been successfully completed, simply type in the file name: wordCounter to run the .exe file and a list of words printed out in alphabetical order should be displayed along with the number of times they occur in the test file.

> After everything has been Pre-processed, linked, assembled and compiled, type in the command line "nmake clean" which is used to clean any junk files necessary, ie any junk .exe/.obj files.

# Application Interface 1
This is the User Interface for the Command Line Application.
![Application1](https://user-images.githubusercontent.com/29733613/62426375-e35b1100-b6db-11e9-8c0d-029cef5ce66d.PNG)

# Word Counter 1
> This is a portion of the words that have been counted from the file.

![Application2](https://user-images.githubusercontent.com/29733613/62426381-04bbfd00-b6dc-11e9-8a54-42b7cb7aacaa.PNG)

# Word Counter 2
> This is another portion of the words counted from the file.

![Application3](https://user-images.githubusercontent.com/29733613/62426392-20bf9e80-b6dc-11e9-8105-fdcec2e8af94.PNG)

# Application Files
> These are all the files that have been used to build the Application.

![Files](https://user-images.githubusercontent.com/29733613/62426398-38972280-b6dc-11e9-8d44-69a35d5b70b2.PNG)
