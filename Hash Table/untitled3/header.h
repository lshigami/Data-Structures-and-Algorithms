#include <bits/stdc++.h>

using namespace std;
#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H

const double A = (sqrt(5) - 1) / 2.0;

template<class T>
class Node {
public:
    T key;
    Node<T> *next;
};

template<class T>
class HashTable {
private:
    Node<T> **table;
    int m;
    string filename;
public:
    HashTable(int size, string outputfile);

    ~HashTable();

    int Hash(T key);

    void Insert(T key);

    void Search(T key);
};


#endif //UNTITLED3_HEADER_H
