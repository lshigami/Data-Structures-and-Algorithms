#include <bits/stdc++.h>

using namespace std;
struct Node {
    int key;
    Node *left;
    Node *right;
    int h;
};

Node *createNode(int data) {
    return new Node{data, nullptr, nullptr, 1};
}

int Height(Node *root) {
    return root == nullptr ? 0 : root->h;
}

int BalanceFactor(Node *root) {
    return Height(root->left) - Height(root->right);
}

Node *RightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    x->h = max(Height(x->left), Height(x->right)) + 1;
    y->h = max(Height(y->left), Height(y->right)) + 1;
    return x;
}

Node *LeftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;
    x->h = max(Height(x->left), Height(x->right)) + 1;
    y->h = max(Height(y->left), Height(y->right)) + 1;
    return y;
}

void Insert(Node *&root, int x) {
    if (root == nullptr) root = createNode(x);
    if (x < root->key) Insert(root->left, x);
    else if (x > root->key) Insert(root->right, x);
    else return;
    root->h = 1 + max(Height(root->left), Height(root->right));
    int balance = BalanceFactor(root);
    //left left
    if (balance > 1 && x < root->left->key) {
        root = RightRotate(root);
        return;
    }
    //right right
    if (balance < -1 && x > root->right->key) {
        root = LeftRotate(root);
        return;
    }
    // left right
    if (balance > 1 && x > root->left->key) {
        root->left = LeftRotate(root->left);
        root = RightRotate(root);
        return;
    }
    // right left
    if (balance < -1 && x < root->right->key) {
        root->right = RightRotate(root->right);
        root = LeftRotate(root);
        return;
    }
}

Node *MinNode(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

void Delete(Node *&root, int x) {
    if (root == nullptr) return;

    if (x < root->key) Delete(root->left, x);
    else if (x > root->key) Delete(root->right, x);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node *temp = MinNode(root->right);
            root->key = temp->key;
            Delete(root->right, temp->key);
        }
    }

    if (root == nullptr) return;

    root->h = 1 + max(Height(root->left), Height(root->right));
    int balance = BalanceFactor(root);

    if (balance > 1) {
        if (BalanceFactor(root->left) >= 0) root = RightRotate(root);
        else {
            root->left = LeftRotate(root->left);
            root = RightRotate(root);
        }
    } else if (balance < -1) {
        if (BalanceFactor(root->right) <= 0) root = LeftRotate(root);
        else {
            root->right = RightRotate(root->right);
            root = LeftRotate(root);
        }
    }
}
void levelOrder(Node*root){
    if(root== nullptr) return;
    queue<Node*>q;
    q.push(root);
    while (!q.empty()){
        Node*top=q.front();
        q.pop();
        cout<<top->key<<" ";
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }
}

bool IsAvl(Node*root){
    if(root== nullptr) return true;
    return abs(Height(root->left) - Height( root->right))<=1
    && IsAvl(root->left)
    && IsAvl(root->right);
}
int main() {
    Node*avl= nullptr;

    for(int i=0;i<6;i++){
        int x; cin>>x;
        Insert(avl,x);
    }
    //Delete(avl,12);
    levelOrder(avl);
}