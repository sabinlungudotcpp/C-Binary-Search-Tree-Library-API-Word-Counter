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
