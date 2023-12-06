#include <bits/stdc++.h>
using namespace  std;
struct Node{
    int key;
    Node*left;
    Node*right;
    int height;
};
Node*CreateNode(int x){
    return new Node{x, nullptr, nullptr,1};
}
int Height(Node*root){
    if(root== nullptr) return 0;
    return root->height;
}

Node*rightRotate(Node*a){
    Node*b=a->left;
    Node*c=b->right;
    b->right=a;
    a->left=c;
    a->height=max(Height(a->left), Height(a->right))+1;
    b->height=max(Height(b->right), Height(b->left))+1;
    return b;
}

Node*leftRotate(Node*a){
    Node*b=a->right;
    Node*c=b->left;
    b->left=a;
    a->right=c;
    a->height=max(Height(a->left), Height(a->right))+1;
    b->height=max(Height(b->right), Height(b->left))+1;
    return b;
}

int BalanceFactor(Node*root){
    if (root==nullptr) return 0;
    return Height(root->left)- Height(root->right);
}

void Insert(Node*&root,int key){
    if(root==nullptr) {
        root= CreateNode(key);
        return;
    }
    if(key<root->key){
        Insert(root->left,key);
    }
    else if(key>root->key){
        Insert(root->right,key);
    }
    else return;

    root->height=1+max(Height(root->left), Height(root->right));
    int balancefactor= BalanceFactor(root);
    //left-left
    if(balancefactor>1 && key <root->left->key){
        root= rightRotate(root);
        return;
    }
    //right right
    if(balancefactor<-1 && key>root->right->key){
        root= leftRotate(root);
        return;
    }
    //left right  :: left child then right root
    if(balancefactor>1 && key>root->left->key){
        root->left= leftRotate(root->left);
        root= rightRotate(root);
    }
    // right left
    if(balancefactor<-1 && key<root->right->key){
        root->right= rightRotate(root->right);
        root= leftRotate(root);
        return;
    }
}

bool IsAVL(Node*node){
    if (node==nullptr) return true;
    if(BalanceFactor(node) >1 || BalanceFactor(node) <-1) return false;
    return IsAVL(node->left) && IsAVL(node->right);
}

int main() {

}
