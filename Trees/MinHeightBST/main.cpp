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

Node* createBST(vector<int> arr, int start, int end){
    if(start > end) return nullptr;
    int mid = start + (end-start)/2;

    Node *root = new Node(arr[mid]);
    root->left = createBST(arr, start, mid-1);
    root->right = createBST(arr, mid+1, end);
    return root;
}

void inOrder(Node *root){
    if(!root) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *root = createBST(arr, 0, arr.size()-1);
    inOrder(root);
    return 0;
}
