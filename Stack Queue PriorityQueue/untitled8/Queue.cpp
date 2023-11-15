#include "Queue.h"

// Explicit instantiations
template class Queue<int>;

template class Queue<float>;

template class Queue<double>;

template class Queue<char>;

template
class Queue<string>;

//0(1)
template<class T>
Queue<T>::Queue() {
    // Initialize head and tail to nullptr
    this->head = this->tail = nullptr;
}

//O(n) vi phai duyet qua tat ca phan tu roi gan gia tri queue = sourcequeue
template<class T>
Queue<T>::Queue(const Queue<T> &sourceQueue) {
    // Create node temp equal to node head of source queue
    Node *temp = sourceQueue.head;
    // if source queue is empty, init this queue as empty
    if (temp == nullptr) {
        this->head = this->tail = nullptr;
    } else {
        //Create first node with data= data's source queue
        head = new Node{temp->data, nullptr};
        // Create one node for running with node temp
        Node *runningNode = head;
        //Node temp move to next node
        temp = temp->next;
        // Tranverse remain node in source queue
        while (temp != nullptr) {
            runningNode->next = new Node;    //Set pointer to the next node = new Node
            runningNode = runningNode->next; //Move runningNode to new Node
            runningNode->data = temp->data;  //Set data of runningNode is data's temp node
            temp = temp->next;               //Move temp node to below
        }
        this->tail = runningNode;           // set tail=running node
        tail->next = nullptr;               // set the next pointer to null
    }
}

//O(n) vi phai duyet qua tat ca cac phan tu de xoa
template<class T>
Queue<T>::~Queue() {
    // Dequeue all elements until queue is empty
    while (!IsEmpty()) {
        deQueue();
    }
}

//O(1)
template<class T>
bool Queue<T>::IsEmpty() {
    // Queue is empty if head is nullptr
    return this->head == nullptr;
}

//O(1)
template<class T>
void Queue<T>::enQueue(const T &data) {
    // Create a new node with data and next as nullptr
    Node *NewNode = new Node{data, nullptr};
    if (IsEmpty()) {
        // If queue is empty, head and tail = new node
        this->head = this->tail = NewNode;
    } else {
        //Add new node at the end of the queue
        tail->next = NewNode;
        //Set tail= newnode
        tail = NewNode;
    }
}

//O(1)
template<class T>
void Queue<T>::deQueue() {
    if (IsEmpty()) {
        cout << "The Queue Is Empty So Unable To Dequeue";
        return;
    }
    // Create temp node to delete the node
    Node *del = this->head;
    // Move head to next node
    this->head = this->head->next;
    // case : queue has only one node
    if (head == nullptr) {
        tail = nullptr;
    }
    delete del;
}

//O(1)
template<class T>
T Queue<T>::GetHead() {
    if (IsEmpty()) {
        cout << "The Queue Is Empty";
        throw runtime_error("The Queue Is Empty So Unable Get HeadValue");

    }
    // Return the data's head element
    return head->data;
}

//O(n)  vi phai gan tung phan tu tu hang doi nguon
//REF http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &sourceQueue) {
    if (this == &sourceQueue) {
        // If source queue = this queue, return a reference to this object
        return *this;
    }
    // Pop all elements until this queue is empty
    while (!IsEmpty()) {
        deQueue();
    }
    // assign each element of this queue equal to source queue
    // implement code like copy constructor
    Node *temp = sourceQueue.head;
    if (temp != nullptr) {
        head = new Node;
        head->data = temp->data;
        Node *newPtr = head;
        temp = temp->next;

        while (temp != nullptr) {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->data = temp->data;
            temp = temp->next;
        }
        tail = newPtr;
        tail->next = nullptr;
    }
    // Return a reference to this object
    return *this;
}
