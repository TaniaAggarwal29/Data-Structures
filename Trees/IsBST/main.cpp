#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this->key = key;
        left = right  = NULL;
    }
};

struct Tree{
    int min, max;
    bool isbst;
};

Tree checkBST(Node *root){
    Tree t;
    if(!root){
        t.min = INT_MAX;
        t.max = INT_MIN;
        t.isbst = true;
    }
    else if (!root->left and !root->right){
        t.min = root->key;
        t.max = root->key;
        t.isbst = true;
    }
    else if (!root->right){
        Tree Left = checkBST(root->left);
        t.min = min(Left.min, root->key);
        t.max = max(Left.max, root->key);
        t.isbst = Left.isbst and Left.max<root->key;
    }
    else if (!root->left){
        Tree Right = checkBST(root->right);
        t.min = min(Right.min, root->key);
        t.max = max(Right.max, root->key);
        t.isbst = Right.isbst and Right.min>root->key;
    }
    else{
        Tree Left = checkBST(root->left);
        Tree Right = checkBST(root->right);
        t.min = min(root->key, min(Left.min, Right.min));
        t.max = min(root->key, max(Left.max, Right.max));
        t.isbst = Left.isbst and Right.isbst and Left.max<root->key and Right.min>root->key;
    }
    return t;

}

bool isBST(Node * root){
    //complete this method
    return checkBST(root).isbst;
}

int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    cout << isBST(root) << endl;
    return 0;
}




