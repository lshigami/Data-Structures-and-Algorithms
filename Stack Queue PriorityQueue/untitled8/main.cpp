#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

int main() {
    // giai thich code o mini-report

//    Stack<int> st;
//    if (st.IsEmpty()) {
//        cout << "Is empty";
//    } else {
//        cout << "Not empty";
//    }
//    st.Push(5);
//    if (st.IsEmpty()) {
//        cout << endl << "Is empty";
//    } else {
//        cout << endl << "Not empty";
//    }
//    cout << endl << st.GetTop();
//    for (int i = 1; i < 5; i++) {
//        st.Push(i);
//    }
//    cout << endl << st.GetTop();
//    Stack<int> st_cc(st);
//    st_cc.Push(10);
//    Stack<int> st_op;
//    st_op = st_cc;
//    cout << endl << "Value of stack (operator)" << endl;
//    while (!st_op.IsEmpty()) {
//        cout << st_op.GetTop() << endl;
//        st_op.Pop();
//    }
//    if (st_op.IsEmpty()) cout << "Is Empty" << endl; else cout << "Not empty" << endl;
//    int x = st_op.GetTop();
//    cout << x;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//    Queue<char> q;
//    if (q.IsEmpty()) cout << "Is Empty" << endl;
//    else cout << "Not Empty" << endl;
//    for (int i = 65; i < 71; i++) {
//        q.enQueue((char) i);
//    }
//    if (q.IsEmpty()) cout << "Is Empty" << endl;
//    else cout << "Not Empty" << endl;
//
//    cout << "q head : " << q.GetHead() << endl;
//    q.deQueue();
//    cout << "q head after dequeue: " << q.GetHead() << endl;
//
//    Queue<char> q_cc(q);
//    q_cc.deQueue();
//    cout << "q_cc head after de_queue: " << q_cc.GetHead() << endl;
//    Queue<char> q_op;
//    q_op = q_cc;
//    while (!q_op.IsEmpty()) {
//        cout << q_op.GetHead() << " ";
//        q_op.deQueue();
//    }

//----------------------------------------------------------------------------------------------------------------------
//    PriorityQueue<string> pq;
//    if (pq.IsEmpty()) cout << "Is empty" << endl; else cout << "Not empty" << endl;
//    string a[8] = {"nguyen", "quang", "thang", "ma", "so", "sinh", "vien", "22120334"};
//    for (int i = 0; i < 8; i++) {
//        pq.Push(a[i]);
//    }
//    if (pq.IsEmpty()) cout << "Is empty" << endl; else cout << "Not empty" << endl;
//
//    cout << "Maximum value of pq is : " << pq.GetMaximum() << endl;
//    PriorityQueue<string> pq_cc = pq;
//    cout << "Maximum value of pq_cc is : " << pq_cc.GetMaximum() << endl;
//    pq_cc.Pop();
//
//    PriorityQueue<string> pq_op;
//    pq_op = pq_cc;
//    while (!pq_op.IsEmpty()) {
//        cout << pq_op.GetMaximum() << " ";
//        pq_op.Pop();
//    }

}