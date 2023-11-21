#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

struct Node {
    int key;
    Node *p_next;
};
struct List {
    Node *p_head;
};
bool addTail(List *L, int data) {
    Node *newNode = new Node{data, nullptr};
    if (newNode == nullptr) {
        return false;
    }
    if (L->p_head == nullptr) {
        L->p_head = newNode;
        return true;
    }
    Node *temp = L->p_head;
    while (temp->p_next!= nullptr) {
        temp = temp->p_next;
    }
    temp->p_next = newNode;
    return true;
}
void reverseList(List *L) {
    if (L->p_head == nullptr) return;
    if (L->p_head->p_next == nullptr) return;
    Node *temp = L->p_head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while (temp) {
        next = temp->p_next;
        temp->p_next = prev;
        prev = temp;
        temp = next;
    }
    L->p_head = prev;
}

struct TreeNode {
    int key;
    TreeNode *p_left;
    TreeNode *p_right;
};
TreeNode *createNode(int data) {
    return new TreeNode{data, nullptr, nullptr};
}
void NLR(TreeNode *root) {
    if (root) {
        cout << root->key << " ";
        NLR(root->p_left);
        NLR(root->p_right);
    }
}
int SumNode(TreeNode *root) {
    int sum = 0;
    if (root == nullptr) return 0;
    return root->key + SumNode(root->p_right) + SumNode(root->p_left);
}
int countLeaf(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->p_left == nullptr && root->p_right == nullptr) return 1;
    int leafleft = (root->p_left) ? countLeaf(root->p_left) : 0;
    int leafright = (root->p_right) ? countLeaf(root->p_right) : 0;
    return leafleft + leafright;
}
TreeNode *search(TreeNode *root, int x) {
    if (root == nullptr) return nullptr;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->key == x) return temp;
        if (temp->p_left) q.push(temp->p_left);
        if (temp->p_right) q.push(temp->p_right);
    }
    return nullptr;
}

void Insert(TreeNode *&root, int x) {
    TreeNode *newNode = createNode(x);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    TreeNode *temp = root;
    TreeNode *prev = nullptr;
    while (temp) {
        prev = temp;
        if (x > temp->key) temp = temp->p_right;
        else if (x < temp->key) temp = temp->p_left;
        else return;
    }
    if (x > prev->key) prev->p_right = newNode;
    else prev->p_left = newNode;
}

TreeNode *findMin(TreeNode *root) {
    while (root->p_left) {
        root = root->p_left;
    }
    return root;
}

void Remove(TreeNode *&root, int x) {
    if (root == nullptr) return;
    if(root->key==x && root->p_left== nullptr && root->p_right== nullptr) {
        root= nullptr;
        return;
    }
    TreeNode *temp = root;
    TreeNode *prev = nullptr;
    while (temp && temp->key!=x) {
        prev = temp;
        if (x > temp->key) temp = temp->p_right;
        else if (x < temp->key) temp = temp->p_left;
        else break;
        if (temp == nullptr) return;
    }
    if(temp->p_left== nullptr && temp->p_right== nullptr) {
        if(prev->key>x) {
            delete temp;
            prev->p_left= nullptr;
        }
        else {
            delete temp;
            prev->p_right= nullptr;
        }
    }
    else if(temp->p_right== nullptr){
        temp->key=temp->p_left->key;
        delete temp->p_left;
        temp->p_left= nullptr;
    }
    else if(temp->p_left== nullptr){
        temp->key=temp->p_right->key;
        delete temp->p_right;
        temp->p_right= nullptr;

    }
    else {
        TreeNode*min= findMin(temp->p_right);
        temp->key=min->key;
        Remove(temp->p_right,min->key);
    }
}

int main() {
//    List *l = new List{nullptr};
//    for (int i = 1; i <= 5; i++) {
//        addTail(l, i);
//    }
//    reverseList(l);
//    while (l->p_head) {
//        cout << l->p_head->key << " ";
//        l->p_head = l->p_head->p_next;
//    }

    TreeNode*root= nullptr;
    int a[8]={10,5,20,3,7,15,35,6};
    for(int x:a){
        Insert(root,x);
    }
    TreeNode*run1=root;
    TreeNode*run2=root;
    NLR(run1);
    int sum=accumulate(a,a+8,0);
    cout<<endl;
    cout<<"CHECK SUM  " <<sum<<" "<<SumNode(root)<<endl;
    TreeNode*mustsearch = search(root,99);
    if(mustsearch) cout<<mustsearch->key<<endl; else cout<<"NotFind";
    cout<<endl;
    cout<<countLeaf(root)<<endl;
    Remove(root,20);
    NLR(run2);

}
