//
// Created by Anas Khafagi on 3/1/17.
//

#include "Tokenizer.hpp"


string *Tokenizer::GetTokens() {
    string line;
    while (true) {
        tokens.clear();
        int flag;
        cout << "> ";
        getline(cin, line);
        get_tokens(line);
        set_flag(tokens, flag);
        if (tokens.size() > 2) {
            cout << "ERROR! Incorrect number of tokens found." << endl;
            continue;
        }
        if (line.length() > 65) {
            cout << "ERROR! Input string too long.\n";
            continue;
        }
        switch (flag) {
            case 0:
                cout << "ERROR! Expected STR.\n";
                continue;

            case 1:
                cout << "ERROR! Expected STR INT.\n";
                continue;
        }
        break;
    }
    string *temp = new string [2];
    int i = 0;
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end();it++)
        temp[i++] = *it;
    if (tokens.size() < 2)
        temp[1] = "";
    return temp;
}

vector<string> Tokenizer::get_tokens(string line) {
    string delimiters = " \t\n ";
    string::size_type last = line.find_first_not_of(delimiters, 0);
    string::size_type first = line.find_first_of(delimiters, last);
    string token = line.substr(last, first - last);
    while (first != string::npos || last != string::npos) {
        token = line.substr(last, first - last);
        tokens.push_back(token);
        last = line.find_first_not_of(delimiters, first);
        first = line.find_first_of(delimiters, last);
    }
    return tokens;
}

void Tokenizer::set_flag(vector<string> tokens, int &flag) {
    flag = 0;
    for (unsigned int i = 0; i < tokens.size(); i++) {
        if (flag == -1 && is_digit(tokens[i]))
            break;
        else if (flag == -1 && !is_digit(tokens[i]) && tokens[i] != "") {
            flag = 1;
            break;
        }
        if (is_digit(tokens[i]) && tokens.size() == 2) {
            flag = 1;
        } else if (is_digit(tokens[i]) && tokens.size() == 1) {
            flag = 0;
        } else
            flag = -1;
    }
}

bool Tokenizer::is_digit(string token) {
    for (string::iterator it = token.begin(); it != token.end();it++) {
        if (isdigit(*it) == 0)
            return false;
    }
    return true;

}

