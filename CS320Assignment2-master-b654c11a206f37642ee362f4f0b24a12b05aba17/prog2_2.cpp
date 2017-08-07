//
// Created by Anas Khafagi on 3/2/17.
//
#include "prog2_2.hpp"
#include "Tokenizer.hpp"

int main(int argc, char ** argv){
    cout << "Assignment #2-2, Anas Khafagi, anas.khafagi@gmail.com"<<endl;
    if (argc != 2) {
        cout << "ERROR! Program accepts 1 command line argument." << endl;
        return 1;
    }
    errno = 0;
    int max_inputs = (int)strtol(argv[1], NULL, 10);
    if (errno != 0) {
        cout << " ERROR! Program expected integer argument." << endl;
        return 1;
    }

    int num_inputs;
    Tokenizer token;
    do {
        string* tokens = token.GetTokens();

        if (strncasecmp(tokens[0].c_str(), "quit", tokens[0].length()) == 0)
            return 0;

        print_tokens(tokens);
        num_inputs++;
    }
    while (num_inputs != max_inputs);
}

void print_tokens(string* tokens) {
    for (unsigned int i = 0; i < 2; i++) {
        if(tokens[i] == "")
            continue;
        else if (is_digit(tokens[i]))
            cout << "INT ";
        else {
            cout << "STR ";
        }
    }
    cout << endl;
}

bool is_digit(string token) {
    for (string::iterator it = token.begin(); it <token.end();it++) {
        if (isdigit(*it) == 0)
            return false;
    }
    return true;
}