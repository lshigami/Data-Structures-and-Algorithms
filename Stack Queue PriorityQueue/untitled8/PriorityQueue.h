//
// Created by yanke on 10/30/2023.
//
#include <bits/stdc++.h>

using namespace std;
#ifndef UNTITLED8_PRIORITYQUEUE_H
#define UNTITLED8_PRIORITYQUEUE_H

// Define template for class PriorityQueue
// MaxHeap
template<class T>
class PriorityQueue {
private:
    T *heap;                                                // Pointer to heap array
    int size;                                               // Curremt size of PriorityQueue
    int capacity;                                           // Max capacity of the PriorityQueue
    void Heapify(int i);                                    // Function to maintain Heap
public:
    PriorityQueue();                                        // Default constructor
    PriorityQueue(const PriorityQueue &);                   // Copy constructor
    ~PriorityQueue();                                       // Destructor
    bool IsEmpty();                                         // Function to check if the PriorityQueue is empty
    void Push(const T &data);                                // Function to Push data type T into the PriorityQueue
    void
    Pop();                                             // Function to remove the maximum element from the PriorityQueue
    T
    GetMaximum();                                         // Function to get the maximum element from the PriorityQueue
    PriorityQueue<T> &operator=(const PriorityQueue<T> &);   // Overload operator '=' for PriorityQueue
};

#endif //UNTITLED8_PRIORITYQUEUE_H
