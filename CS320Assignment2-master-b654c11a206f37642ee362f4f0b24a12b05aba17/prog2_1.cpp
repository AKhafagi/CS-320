//
// Created by Anas Khafagi on 2/28/17.
//
#include "prog2_1.hpp"

using namespace std;


int main(int argc, char **argv) {
    cout << "Assignment #2-1, Anas Khafagi, anas.khafagi@gmail.com" << endl;
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
    string line;
    int num_inputs = 0;
    vector<string> tokens;
    int flag;
    do {
        cout << "> ";
        getline(cin, line);
        tokens = get_tokens(line);
        set_flag(tokens, flag);
        if (tokens.size() > 2) {
            cout<<"ERROR! Incorrect number of tokens found.\n";
            num_inputs++;
            continue;
        }
        if (line.length() > 65) {
            cout<<"ERROR! Input string too long.\n";
            num_inputs++;
            continue;
        }
        switch (flag) {
            case 0:
                cout<<"ERROR! Expected STR.\n";
                num_inputs++;
                continue;

            case 1:
                cout<<"ERROR! Expected STR INT.\n";
                num_inputs++;
                continue;
        }

        if (strncasecmp(tokens[0].c_str(), "quit", tokens[0].length()) == 0)
            return 0;

        print_tokens(tokens);
        num_inputs++;

    } while (num_inputs != max_inputs);


}

vector<string> get_tokens(string line) {
    string delimiters = " \t\n ";
    string::size_type last = line.find_first_not_of(delimiters, 0);
    string::size_type first = line.find_first_of(delimiters, last);
    vector<string> tokens;
    string token = line.substr(last, first - last);
    while (first != string::npos || last != string::npos) {
        token = line.substr(last, first - last);
        tokens.push_back(token);
        last = line.find_first_not_of(delimiters, first);
        first = line.find_first_of(delimiters, last);
    }
    return tokens;
}

void set_flag(vector<string> tokens, int &flag) {
    flag = 0;
    for (unsigned int i = 0; i < tokens.size(); i++) {
        if (flag == -1 && is_digit(tokens[i]))
            break;
        else if (flag == -1 && !is_digit(tokens[i])) {
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

void print_tokens(vector<string> tokens) {
    for (unsigned int i = 0; i < tokens.size(); i++) {
        if (is_digit(tokens[i]))
            cout << "INT ";
        else {
            cout << "STR ";
        }
    }
    cout << endl;
}

bool is_digit(string token) {
    for (string::iterator it = token.begin(); it < token.end(); it++) {
        if (isdigit(*it) == 0)
            return false;
    }
    return true;
}