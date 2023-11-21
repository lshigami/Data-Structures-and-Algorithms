#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
struct List{
    Node*head;
    Node*tail;
};
Node* createNode(int data){
    return new Node{data,nullptr};
}
List* createList(Node*node){
    return new List{node,node};
}
bool addHead(List*&L,int x){
    Node*newNode= createNode(x);
    if(newNode== nullptr) return false;
    if(L->head==nullptr) {
        L->head=L->tail=newNode;
        return true;
    }
    newNode->next=L->head;
    L->head=newNode;
    return true;
}
bool addTail(List*&L,int x){
    Node*newNode= createNode(x);
    if(newNode== nullptr) return false;
    if(L->head==nullptr) {
        L->head=L->tail=newNode;
        return true;
    }
    L->tail->next=newNode;
    L->tail=newNode;
    return true;
}
void removeHead(List*&L){
    if(L->head==nullptr) return;
    if(L->head==L->tail) {
        L->head=L->tail=nullptr;
        return  ;
    }
    Node*temp=L->head;
    L->head=L->head->next;
    delete temp;
}
void removeTail(List*&L){
    if(L->head==nullptr) return;
    if(L->head==L->tail) {
        L->head=L->tail=nullptr;
        return  ;
    }
    Node*temp=L->head;
    while(temp->next->next){
        temp=temp->next;
    }
    Node*del=temp->next;
    temp->next= nullptr;
    delete del;
    L->tail=temp;
}
void removeall(List*&L){
    if(L->head== nullptr) return;
    while (L->head){
        removeHead(L);
    }
}
int printList(List *L){
    int cnt=0;
    Node*temp=L->head;
    while (temp){
        cnt++;
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return cnt;
}
int size(List *L){
    int cnt=0;
    Node*temp=L->head;
    while (temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
List*reverseList(List*&L){
    if(L->head== nullptr || L->head->next== nullptr) return L;
    L->tail=L->head;
    Node*head=L->head;
    Node*prev= nullptr;
    Node*next= nullptr;
    while (head){
        next=head->next;
        head->next=prev;
        prev=head;
        head= next;
    }
    L->head=prev;
    return L;
}
bool removeElement(List*&L, int key){
    bool ok=false;
    if(L->head== nullptr) return true;
    while(L->head && L->head->data==key){
        ok= true;
        L->head=L->head->next;
    }
    Node*temp=L->head;
    while(temp && temp->next){
        while(temp->next && temp->next->data==key){
            ok= true;
            temp->next=temp->next->next;
        }
        temp=temp->next;
        if(temp== nullptr) L->tail= nullptr;
    }
    return ok;
}

void addPos(List*L,int data, int pos){
    if(pos==0){
        addHead(L,data);
        return;
    }
    if(pos==size(L)) {
        addTail(L,data);
        return;
    }
    Node*temp=L->head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    Node*newNode= createNode(data);
    newNode->next=temp->next;
    temp->next=newNode;
}

struct PriorityQueue{
    int size;
    int capacity;
    int *a;
};
void createPriorityQueue(PriorityQueue &pq){
    pq.size=0;
    pq.capacity=1000;
    pq.a=new int[pq.capacity];
}
void Heapify(PriorityQueue &pq, int i){
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    if(l<pq.size && pq.a[l]>pq.a[max]) max=l;
    if(r<pq.size && pq.a[r]>pq.a[max]) max=r;
    if(max!=i){
        swap(pq.a[i],pq.a[max]) ;
        Heapify(pq,max);
    }
}
void Push(PriorityQueue &pq, int data){
    if(pq.size==pq.capacity){
        pq.capacity*=2;
        int *temp = new int[pq.capacity];
        for(int i=0;i<pq.size;i++){
            temp[i]=pq.a[i];
        }
        delete[] pq.a;
        pq.a=temp;
    }
    pq.a[pq.size++]=data;
    for(int i=pq.size/2-1;i>=0;i--){
        Heapify(pq,i);
    }
}
int pop(PriorityQueue &pq){
    if(pq.size<=0) return -1;
    int ans=pq.a[0];
    pq.a[0]=pq.a[pq.size-1];
    pq.size--;
    Heapify(pq,0);
    return ans;
}

int main() {
    PriorityQueue pq;
    createPriorityQueue(pq);
    for(int i=1;i<=5;i++){
        Push(pq,i);
    }
    while(pq.size!=0){
        cout<<pop(pq);
    }
}
