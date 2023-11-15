#include "PriorityQueue.h"

// Explicit instantiations
template class PriorityQueue<int>;

template class PriorityQueue<float>;

template class PriorityQueue<double>;

template class PriorityQueue<char>;

template class PriorityQueue<string>;

// Chieu cao cua cay H=⌈log2(N+1)⌉−1
// Method Heapify voi worstcase se duyet tu root ->den leaf -> do phuc tap thoi gian xem la O(logn)
template<class T>
void PriorityQueue<T>::Heapify(int i) {
    int largest = i; // largest = root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // if left child value > root value
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    // if right child value > root value
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        // Swap root and largest
        swap(heap[i], heap[largest]);
        // Heapifi subtree
        Heapify(largest);
    }
}


//O(1)
template<class T>
PriorityQueue<T>::PriorityQueue() {
    size = 0;   // size =0
    capacity = 100; // init capacity =100
    heap = new T[capacity];   // allocate memory for array
}

//O(n) vi cung duyet qua tat ca cac phan tu
template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &sourcePQ) {
    size = sourcePQ.size;          // copy size from sourcePQ
    capacity = sourcePQ.capacity;  // copy capacity from sourcePQ
    heap = new T[capacity];        // Allocate memory for array
    for (int i = 0; i < size; i++) {
        heap[i] = sourcePQ.heap[i];     // assign each elements this PQ = sourcePQ
    }
}


//  O(n) vi no se giai phong tung phan tu cua mang
//"operator delete[] is a regular function that can be called explicitly just as any other function. But in C++, delete[] is an operator with a very specific behavior: An expression with the delete[] operator, first calls the appropriate destructors for each element in the array , and then calls an array deallocation function."
// REF: https://cplusplus.com/reference/new/operator%20delete[]/
template<class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] heap;            // Deallocate memory array
}


// O(1)
template<class T>
bool PriorityQueue<T>::IsEmpty() {
    return size == 0; // size=0 -> empty
}


//Sao chep mang cu qua mang moi -> O(n)
//Build lai heap -> O(logn)
// -> bigO la O(n+logn) = O(n)
// Chua toi uu , neu dung danh sach lien ket thi viec them phan tu vao cuoi se la O(1) va khong can phai duyet qua de sao chep lai
template<class T>
void PriorityQueue<T>::Push(const T &data) {
    // check if size = capacity -> Increase capacity -> reallocate memory
    if (size == capacity) {
        capacity *= 2;
        // create new dynamic array
        T *temp = new T[capacity];
        // assign old value to new array
        for (int i = 0; i < size; i++) {
            temp[i] = heap[i];
        }
        // delete old memory
        delete[] heap;
        //assign pointer heap= new array
        heap = temp;
    }
    // insert new element at the end , increase size
    heap[size++] = data;
    // build max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(i);
    }
}


// O(logn) = bigO cua ham heapify
template<class T>
void PriorityQueue<T>::Pop() {
    if (size == 0) return;
    // swap max value in heap with last element
    swap(heap[0], heap[size - 1]);
    // decrease size
    size--;
    // heapifi at index 0 to maintain max heap after swap
    Heapify(0);
}

//O(1)
template<class T>
T PriorityQueue<T>::GetMaximum() {
    if (!IsEmpty()) {
        return heap[0];
    }
        //throw exception when try to get value when IsEmpty
    else throw runtime_error("The Queue Is Empty So Unable Get HeadValue");

}

//O(n) vi phai duyet qua tat ca cac phan tu
// REF: http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
template<class T>
PriorityQueue<T> &PriorityQueue<T>::operator=(const PriorityQueue<T> &sourcePQ) {
    // Check for self-assignment
    if (this == &sourcePQ) {
        return *this;
    }
    // Deallocate memory of old heap array
    delete[] heap;
    // copy size of sourcePQ
    size = sourcePQ.size;
    // copy capacity of sourcePQ
    capacity = sourcePQ.capacity;
    // alocate memory
    heap = new T[capacity];
    // copy each element value from source
    for (int i = 0; i < size; i++) {
        heap[i] = sourcePQ.heap[i];
    }
    // return reference to this object
    return *this;
}

