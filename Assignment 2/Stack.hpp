//
// Created by Anas Khafagi on 3/2/17.
//

#ifndef CS_320_STACK_HPP
#define CS_320_STACK_HPP

#include <iostream>
#include <vector>

using namespace std;

class Stack {
public:
    void Push(int data);

    int Pop();

    void Print();

private:
    vector<int> vec;

};


#endif //CS_320_STACK_HPP
