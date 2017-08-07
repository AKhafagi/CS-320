//
// Created by Anas Khafagi on 3/2/17.
//

#include "prog2_3.hpp"

int main(int argc, char ** argv) {
    cout << "Assignment #2-3, Anas Khafagi, anas.khafagi@gmail.com"<<endl;
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
    int num_inputs =0;
    Tokenizer token;
    Stack stack;
    do {
        string* tokens = token.GetTokens();
        int num_token = num_tokens(tokens);
        switch(num_token){
            case 1:
                if(tokens[0] == "pop"){
                    stack.Pop();
                }
                else if(strncasecmp(tokens[0].c_str(), "quit", tokens[0].length()) == 0){
                    stack.Print();
                    return 0;
                }
                break;
            case 2:
                if(tokens[0] == "push"){
                    stack.Push(strtol(tokens[1].c_str(), NULL, 10));
                }
                break;
        }
        num_inputs++;
    }
    while (num_inputs != max_inputs);
    stack.Print();
}

int num_tokens(string * tokens){
    int idx=0;
    int num_token=0;
    while(idx<2){
        if(tokens[idx++] != "")
            num_token++;
    }
    return num_token;
}
