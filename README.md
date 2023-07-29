# Dictionary Implementation using BST in c
This C code provides a simple implementation of a dictionary using a binary search tree (BST) data structure. Users can perform various operations such as insertion, deletion, searching, and traversal on the dictionary.

Features:
The dictionary supports the following functionalities:
Insertion: Users can add new words and their meanings to the dictionary.
Deletion: Words can be removed from the dictionary.
Searching: Users can search for the meaning of a specific word in the dictionary.
Traversal: The program can display all the words and their meanings in the dictionary using an in-order traversal of the BST.
Search Similar Word: The program can search for words that have a similar substring as the given input word.

How to Use:
Run the program and select the desired operation from the menu:
To insert a new word and its meaning, choose option 1 and follow the prompts.
To delete a word, choose option 2 and provide the word to be deleted.
To search for a word and its meaning, choose option 3 and provide the word to be searched.
To display all words and meanings in the dictionary, choose option 4.
To search for similar words, choose option 5 and provide the input word.
The dictionary is implemented using a binary search tree, so words are stored in alphabetical order for efficient searching and traversal.

The dictionary data is stored in a file named "first.txt" located at "F:\DSA Innovative\". The data is loaded into memory from this file when the program starts and is saved back to the file whenever a new word is inserted or deleted.

Note:
The current implementation is basic and does not handle duplicate entries for the same word. The program assumes that the words are case-insensitive, meaning searching for "Hello" and "hello" would yield the same result. The program utilizes string comparison functions for case-insensitive comparisons.

Dependencies:
This C program relies on the standard C libraries, including:
stdio.h: For standard input/output operations.
conio.h: For console input/output operations (used for menu selection).
stdlib.h: For dynamic memory allocation and general functions.
string.h: For string manipulation operations.

Author:
This dictionary implementation is developed by Rushil Prajapati.
