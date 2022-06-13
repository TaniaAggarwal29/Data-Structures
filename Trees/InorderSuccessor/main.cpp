#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int d){
        val = d;
        left = right = nullptr;
    }
};

Node* createBST(Node *root, int key){
    if(!root){
        return new Node(key);
    }
    if(key <= root->val)
        root->left = createBST(root->left, key);
    else
        root->right = createBST(root->right, key);
    return root;
}

int inorderSuccessor(Node *root, Node* target){
    // if right subtree exists
    if(target->right){
        Node *temp = target->right;
        while(temp->left)
            temp = temp->left;
        return temp->val;
    }
    // if right subtree does not exist
    else {
        int succ = -1;
        Node *temp = root;
        while(temp){
            if(temp->val > target->val){
                succ = temp->val;
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return succ;
    }
}

int main() {
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = nullptr;
    for (auto x: arr) {
        root = createBST(root, x);
    }
    cout << inorderSuccessor(root, root->left->right->right) << endl;
    cout << inorderSuccessor(root, root->left) << endl;
    return 0;
}