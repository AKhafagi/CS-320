//
// Created by Anas Khafagi on 3/1/17.
//

#ifndef CS_320_PROG2_1_HPP
#define CS_320_PROG2_1_HPP

#include <string>
#include <iostream>
#include <vector>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

vector<string> get_tokens(string line);

void set_flag(vector<string> tokens, int &flag);
bool is_digit(string token);
void print_tokens(vector<string> tokens);


#endif //CS_320_PROG2_1_HPP
