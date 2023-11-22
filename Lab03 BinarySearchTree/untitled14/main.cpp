#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

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
void LNR(TreeNode *root) {
    if (root) {
        LNR(root->p_left);
        cout << root->key;
        LNR(root->p_right);
    }
}
void LRN(TreeNode *root) {
    if (root) {
        LRN(root->p_left);
        LRN(root->p_right);
        cout << root->key;
    }
}

// Duyet theo muc cua cay
void LevelOrder(TreeNode *root) {
    if (root == nullptr) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->key << " ";
        if (temp->p_left) q.push(temp->p_left);
        if (temp->p_right) q.push(temp->p_right);
    }
}

//Tong tat ca gia tri cua cay
int SumNode(TreeNode *root) {
    int sum = 0;
    if (root == nullptr) return 0;
    return root->key + SumNode(root->p_right) + SumNode(root->p_left);
}

//Dem so leaf cua cay
int countLeaf(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->p_left == nullptr && root->p_right == nullptr) return 1;
    int leafleft = (root->p_left) ? countLeaf(root->p_left) : 0;
    int leafright = (root->p_right) ? countLeaf(root->p_right) : 0;
    return leafleft + leafright;
}

//Tinh chieu cao cua cay
int Height(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->p_left == nullptr && root->p_right == nullptr) return 0;
    int leftHeight = (root->p_left) ? Height(root->p_left) : 0;
    int rightHeight = (root->p_right) ? Height(root->p_right) : 0;
    return 1+max(leftHeight,rightHeight);
}

//Tim level cua node p
int Level(TreeNode*root, TreeNode *p){
    int cnt=0;
    if(root== nullptr || p== nullptr) return 0;
    while(root){
        if(p->key>root->key) root=root->p_right;
        else if(p->key<root->key) root=root->p_left;
        else return cnt;
        cnt++;
    }
    return cnt;
}

//Tim tat ca gia tri < value
int CountLess(TreeNode*root, int value){
    if(root->key<value) return 1 + ((root->p_left) ? CountLess(root->p_left,value):0) + ((root->p_right) ? CountLess(root->p_right,value):0);
    else return 0 + ((root->p_left) ? CountLess(root->p_left,value):0) + ((root->p_right) ? CountLess(root->p_right,value):0);
}

// Kiem tra xem cay co phai la 1 BinarySearchTree hay khong
bool IsBST(TreeNode*root, TreeNode*&prev){
    if(root== nullptr) return true;
    if (!IsBST(root->p_left,prev)) return false;
    if(prev&&prev->key>=root->key) return false;
    prev=root;
    return IsBST(root->p_right,prev);
}
bool IsBST(TreeNode*root){
    if(root== nullptr) return true;
    TreeNode*prev= nullptr;
    return IsBST(root,prev);
}

//Kiem tra xem cay co phai la 1 full Binary Search Tree hay khong
bool ValidFullNode(TreeNode*root){
    return (root->p_left== nullptr && root->p_right== nullptr) || (root->p_left!= nullptr && root->p_right!= nullptr);
}
bool IsFullBST(TreeNode*root){
    if(!ValidFullNode(root))  return false;
    if(root->p_left) if(!IsFullBST(root->p_left)) return false;
    if(root->p_right) if(!IsFullBST(root->p_right)) return false;
    return IsBST(root);
}

//Search 1 gia tri trong cay khong su dung de quy
TreeNode *searchBFS(TreeNode *root, int x) {
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
TreeNode *search(TreeNode *root, int x) {
    if (root == nullptr) return root;
    while (root) {
        if (x > root->key) root = root->p_right;
        else if (x < root->key) root = root->p_left;
        else return root;
    }
    return root;
}

// Them 1 node vao cay
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

// Xoa 1 node khoi cay
TreeNode *findMin(TreeNode *root) {
    while (root->p_left) {
        root = root->p_left;
    }
    return root;
}
void Remove(TreeNode *&root, int x) {
    if (root == nullptr) return;
    if (root->key == x && root->p_left == nullptr && root->p_right == nullptr) {
        delete root;
        root = nullptr;
        return;
    }
    TreeNode *temp = root;
    TreeNode *prev = nullptr;
    while (temp && temp->key != x) {
        prev = temp;
        if (x > temp->key) temp = temp->p_right;
        else if (x < temp->key) temp = temp->p_left;
        else break;
        if (temp == nullptr) return;
    }
    if (temp->p_left == nullptr && temp->p_right == nullptr) {
        if (prev->key > x) {
            delete temp;
            prev->p_left = nullptr;
        } else {
            delete temp;
            prev->p_right = nullptr;
        }
    } else if (temp->p_right == nullptr) {
        temp->key = temp->p_left->key;
        delete temp->p_left;
        temp->p_left = nullptr;
    } else if (temp->p_left == nullptr) {
        temp->key = temp->p_right->key;
        delete temp->p_right;
        temp->p_right = nullptr;

    } else {
        TreeNode *min = findMin(temp->p_right);
        temp->key = min->key;
        Remove(temp->p_right, min->key);
    }
}

// Xoa toan bo cay
void Clear(TreeNode *&root) {
    while (root) {
        Remove(root, root->key);
    }
}

int CountNode(TreeNode*root){
    if(root== nullptr) return 0;
    else return 1+ ((root->p_left) ? CountNode(root->p_left):0) + ((root->p_right) ? CountNode(root->p_right) : 0);
}
TreeNode *createTree(int a[], int n) {
    TreeNode *root = nullptr;
    for (int i = 0; i < n; i++) {
        Insert(root, a[i]);
    }
    return root;
}

int SumInRange(TreeNode*root,int a, int b){
    int sum=0;
    if(root->key>=a && root->key<=b) sum+=root->key;
    return sum+= ((root->p_left) ? SumInRange(root->p_left,a,b) : 0) + ((root->p_right) ? SumInRange(root->p_right,a,b) :0);
}
int countLeafverLess(TreeNode*root, int x){
    if (root== nullptr) return 0;
    if(root->p_right== nullptr && root->p_left== nullptr && root->key<x) return 1;
    return ((root->p_right)? countLeafverLess(root->p_right,x):0 ) + ((root->p_left)? countLeafverLess(root->p_left,x) : 0);
}

bool IsCompletedBST(TreeNode*root){
    if(!IsBST(root)) return false;
    queue<TreeNode*>q;
    q.push(root);
    bool ok= false;
    while (!q.empty()){
        TreeNode*temp=q.front();
        if(temp== nullptr) {
            ok= true;
            q.pop();
            continue;
        }
        else{
            if(ok== true) return false;
        }
        q.push(temp->p_left);
        q.push(temp->p_right);
    }
    return ok;
}
int main() {
    TreeNode *root = nullptr;
    int a[8] = {10, 5, 20, 3, 7, 15, 35, 6};
    root = createTree(a, 8);
    NLR(root);
    int sum = accumulate(a, a + 8, 0);
    cout << endl;
    cout << "CHECK SUM  " << sum << " " << SumNode(root) << endl;
    TreeNode *mustsearch = search(root, 6);
    if (mustsearch) cout << "FIND " << mustsearch->key << endl; else cout << "NotFind";
    cout << endl;
//    Remove(root,10);
//    Clear(root);
    cout<<"height is " <<Height(root)<<endl;
    Insert(root,99);
    Insert(root,100);
    Insert(root,200);
    cout<<"height is " <<Height(root)<<endl;
    Remove(root,99);
    Remove(root,100);
    Remove(root,200);
//    Remove(root,6);
    NLR(root);
    cout<<endl;
    cout<<"LEVEL "<<Level(root,mustsearch)<<endl;
    cout<<"IS BST ? "<<IsBST(root)<<endl;
    cout<<"IS FULL BST ? "<<IsFullBST(root)<<endl;
    cout<<"SUM IN RANGE : "<<SumInRange(root,6,20)<<endl;
    cout<<"COUNT LEAF LESS X "<<countLeafverLess(root,30)<<endl;
    NLR(root);
    cout<<endl<<"has node : "<<CountNode(root);
}
