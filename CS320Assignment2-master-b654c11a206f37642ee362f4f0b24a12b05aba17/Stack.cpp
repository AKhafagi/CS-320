//
// Created by Anas Khafagi on 3/2/17.
//

#include "Stack.hpp"

void Stack::Push(int data) {
    vec.push_back(data);
}

int Stack::Pop() {
    int temp = vec.back();
    vec.pop_back();
    return temp;
}

void Stack::Print() {
    if (vec.size() == 0) {
        cout << "[ ]"<<endl;
        return;
    }
    cout << "[ ";
    for (vector<int>::iterator it = vec.begin();it != vec.end();it++) {
        cout << *it << " ";
    }
    cout << "]" << endl;
}