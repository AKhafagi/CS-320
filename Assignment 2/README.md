Anas Khafagi

Anas.khafagi@gmail.com

Prog2_1.hpp: Prog2_1 header files to include all the functions used in this part of the assigment.

prog2_1.cpp: takes one command line argument the number of times the program
runs the program then prompts user for one or 2 tokens and prints wether token is STR or INT. Program runs until the user inputs quit (case insensitive).
valid Inputs form: STR or STR INT, loops until input is valid.

prog2_2.hpp: prog2_2 header files to include all the functions used in this part of the assigment.

prog2_2.cpp: reimplements prog2_1 but using the Tokenizer object.

Tokenizer.hpp: The header file for the Tokenizer class.

Tokenizer.cpp: Tokenizer object has one public method GetTokens() that returns a string * of size 2 and follows all the rules implemented by prog2_1

Stack.hpp: the Header file for the Stack class

Stack.cpp: The Stack object will have 3 public methods push,pop and print the push method will push an int onto the stack, the pop will pop an int off the stack and the print will print the elements in the stack from left to right.

prog2_3.h: prog2_3 header files to include all the functions used in this part of the assigment.

prog2_3.cpp: will implement a stack machine using the Stack, and the Tokenizer object, it will take either a push and a param, a pop or a print.
