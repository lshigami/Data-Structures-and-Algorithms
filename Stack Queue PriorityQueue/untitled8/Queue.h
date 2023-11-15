//
// Created by yanke on 10/29/2023.
//
#include <bits/stdc++.h>

using namespace std;
#ifndef UNTITLED8_QUEUE_H
#define UNTITLED8_QUEUE_H

// Define template for class Queue
template<class T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *head;                                  // Pointer to head node of Queue
    Node *tail;                                  // Pointer to tail node of Queue
public:
    Queue();                                     // Default constructor
    Queue(const Queue &);                        // Copy constructor
    ~Queue();                                    // Destructor
    bool IsEmpty();                              // Function to check if Queue is empty
    void enQueue(const T &data);                 // Function to add data type T to the end of the queue
    void deQueue();                              // Function to remove the head element from the queue
    T GetHead();                                 // Function to get the head element of the queue
    Queue<T> &operator=(const Queue<T> &);      // Overload operator '=' for Queue
};


#endif //UNTITLED8_QUEUE_H
