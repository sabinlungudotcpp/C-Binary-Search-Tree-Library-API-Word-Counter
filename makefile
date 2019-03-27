build:
	cl /c test.cpp wordCounter.cpp BinarySearchTree.cpp
		lib /OUT:Coursework2.lib test.obj BinarySearchTree.obj
		cl /c test.cpp 
		link test.obj Coursework2.lib
		del *.obj


singlewordfile-test:
	Coursework2 -i single_words_test.txt


sentencefile-test:
	Coursework2 -i sentences_test.txt

Coursework2:
	cl /c test.cpp BinarySearchTree.cpp
	link test.obj BinarySearchTree.obj Coursework2.lib

clean: 
	del *.exe
	del *.obj
	del *.lib