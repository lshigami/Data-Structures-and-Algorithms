#include "Stack.h"

// Explicit instantiations
template class Stack<int>;

template class Stack<float>;

template class Stack<double>;

template class Stack<char>;

template class Stack<string>;

// O(1)
template<class T>
Stack<T>::Stack() {
    this->Top = nullptr;// Initialize Top to nullptr
};

// O(n) , vi phai duyet qua tat ca cac phan tu de sao chep
template<class T>
Stack<T>::Stack(const Stack<T> &sourceStack) {
    // Create node temp equal to node top of source stack
    Node *temp = sourceStack.Top;
    // if source stack is empty, init this stack as empty
    if (temp == nullptr) {
        this->Top = nullptr;
    } else {
        //Create first node with data= data's source stack
        this->Top = new Node{temp->data, nullptr};
        // Create one node for running with node temp
        Node *runningNode = Top;
        //Node temp move to below node
        temp = temp->next;
        // Tranverse remain node in source stack
        while (temp != nullptr) {
            runningNode->next = new Node;    //Set pointer to the next node = new Node
            runningNode = runningNode->next; //Move runningNode to new Node
            runningNode->data = temp->data;  //Set data of runningNode is data's temp node
            temp = temp->next;               //Move temp node to below
        }
        runningNode->next = nullptr;         //Finally , set pointer to the next node of RunningNode is nullptr (first_element_of_stack)
    }
}

// O(n) vi phai duyet qua tat ca phan tu de xoa
template<class T>
Stack<T>::~Stack() {
    // Pop all the element until stack is empty
    while (!IsEmpty()) {
        Pop();
    }
}

// O(1)
template<class T>
bool Stack<T>::IsEmpty() {
    //return true if top is nullptr
    return this->Top == nullptr;
}

// O(1)
template<class T>
void Stack<T>::Pop() {
    if (IsEmpty()) {
        cout << "The Stack Is Empty So Unable Top Pop";
        return;
    }
    // create temp node to delete
    Node *del = this->Top;
    // move top to next node
    this->Top = Top->next;
    // delete node temp
    delete del;
}

// O(1)
template<class T>
T Stack<T>::GetTop() {
    if (IsEmpty()) {
        cout << "The Stack Is Empty So Unable Get TopValue";
        // throw exception
        throw runtime_error("The Queue Is Empty So Unable Get HeadValue");
    }
    // return the data of top element
    return this->Top->data;
}

//O(1)
template<class T>
void Stack<T>::Push(const T &data) {
    //create new node with data and the next pointer is current top
    Node *NewNode = new Node{data, this->Top};
    // set top = new node
    this->Top = NewNode;
}

//O(n), vi phai gan tung phan tu tu ngan xep nguon
//REF http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &sourceStack) {
    // check if this stack is different to sourcestack
    if (this != &sourceStack) {
        // Pop all elements until this stack is empty
        while (!IsEmpty()) {
            Pop();
        }
        // assign each element of this stack equal to sourcestack
        // implement code like copy constructor
        Node *temp = sourceStack.Top;
        this->Top = new Node{temp->data, nullptr};
        Node *runningNode = Top;
        temp = temp->next;
        while (temp != nullptr) {
            runningNode->next = new Node;
            runningNode = runningNode->next;
            runningNode->data = temp->data;
            temp = temp->next;
        }
        runningNode->next = nullptr;
        // Return a reference to this object
        return *this;
    } else {
        // If source stack = this stack, return a reference to this object
        return *this;
    }
}
