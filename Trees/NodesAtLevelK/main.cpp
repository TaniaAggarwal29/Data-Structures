#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int d) {
        val = d;
        left = right = nullptr;
    }
};

Node* BuildTree(vector<int> arr){
    static int i=0;
    if(arr[i] == -1) return nullptr;

    Node *n = new Node(arr[i]);
    i++;
    n->left = BuildTree(arr);
    i++;
    n->right = BuildTree(arr);
    return n;
}

void printNodesAtLevelK(Node *root, int k){
    if(root == nullptr)
        return;

    if(k==0){
        cout << root->val << " ";
        return;
    }

    printNodesAtLevelK(root->left, k-1);
    printNodesAtLevelK(root->right, k-1);
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BuildTree(arr);
    printNodesAtLevelK(root, 2);
    return 0;
}
