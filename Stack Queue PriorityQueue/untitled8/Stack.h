//
// Created by yanke on 10/29/2023.
//
#include <bits/stdc++.h>

using namespace std;

#ifndef UNTITLED8_STACK_H
#define UNTITLED8_STACK_H

// Define template for class Stack
template<class T>
class Stack {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *Top;                                   // Pointer to node Top of stack
public:
    Stack();                                    // Default constructor
    Stack(const Stack &sourceStack);           // Copy constructor
    ~Stack();                                   // Destructor

    bool IsEmpty();                             // Function to check if Stack is empty
    void Push(const T &data);                   // Function to push data type T to Stack
    void Pop();                                 // Function to top element node on Stack
    T GetTop();                                 // Function to get the value of top element
    Stack<T> &operator=(const Stack<T> &);   // Overload operator '=' for Stack
};

#endif //UNTITLED8_STACK_H
