#include "header.h"

template
class HashTable<int>;


template<class T>
HashTable<T>::HashTable(int size, std::string outputfile) {
    this->m = size;
    this->filename = outputfile;
    table = new Node<T> *[m];
    for (int i = 0; i < m; i++) {
        table[i] = nullptr;
    }
    ofstream COUT(outputfile);
    if (!COUT.is_open()) {
        cout << "Khoi tao that bai" << endl;
    } else {
        cout << "Khoi tao thanh cong" << endl;
        COUT << "[constructor] - khoi tao thanh cong" << endl;
        COUT << "+ m = " << m << endl;
        COUT << "+ output file = " << outputfile << endl;
        COUT.close();
    }
}

template<class T>
HashTable<T>::~HashTable() {
    int deleted = 0;
    for (int i = 0; i < m; i++) {
        Node<T> *temp = table[i];
        bool iscollision = true;
        if (temp && temp->next == nullptr) {
            iscollision = false;
        }
        while (temp) {
            Node<T> *prev = temp;
            temp = temp->next;
            delete prev;
            if (iscollision) deleted++;
        }
        table[i] = nullptr;
    }
    delete[] table;
    table = nullptr;
    ofstream COUT(filename, ios::app);
    COUT << "[destructor] – huy bo thanh cong" << endl;
    COUT << "+ so phan tu xung dot da delete = " << deleted << endl;
    COUT << "+ da delete bang T " << endl;
    COUT.close();
}

template<class T>
void HashTable<T>::Insert(T key) {
    static int i =1;
    int index = Hash(key);
    Node<T> *NewNode = new Node<T>{key, nullptr};
    NewNode->next = table[index];
    table[index] = NewNode;
    ofstream COUT(this->filename, ios::app);
    COUT << "[insert "<<i<< "] – thanh cong" << endl;
    COUT << "+ key = " << key << endl;
    COUT << "+ hash value = " << index << endl;
    if (table[index]->next != nullptr) {
        COUT << "+ xung dot = [co] " << endl;
    } else {
        COUT << "xung dot = [khong] " << endl;
    }
    i++;
    COUT.close();
}

template<class T>
void HashTable<T>::Search(T key) {
    static int i=1;
    int index = Hash(key);
    ofstream COUT(this->filename, ios::app);
    bool found = false;
    Node<T> *temp = table[index];
    while (temp) {
        if (temp->key == key) {
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        COUT << "[search "<<i<< "] - tim thay" << endl;
    } else {
        COUT << "[search "<<i<< "] - khong tim thay" << endl;
    }
    COUT << "+ key = " << key << endl;
    COUT << "+ hash value = " << index << endl;
    if (table[index] && table[index]->next != nullptr) {
        COUT << "xung dot = [co] " << endl;
    } else {
        COUT << "xung dot = [khong] " << endl;
    }
    i++;
    COUT.close();
}

template<class T>
int HashTable<T>::Hash(T k) {
    return floor(m * (fmod((double) k * A, 1)));
}