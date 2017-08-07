//
// Created by Anas Khafagi on 3/1/17.
//

#ifndef CS_320_TOKENZIER_HPP
#define CS_320_TOKENZIER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Tokenizer {
public:
    string *GetTokens();

private:
    vector<string> tokens;

    void set_flag(vector<string>, int &);

    bool is_digit(string token);

    vector<string> get_tokens(string line);

};


#endif //CS_320_TOKENZIER_HPP
