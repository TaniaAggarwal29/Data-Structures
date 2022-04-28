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

struct LinkedList{
    Node *head, *tail;
};

LinkedList flattenBST(Node *root){
    LinkedList l;
    // No Root
    if(!root){
        l.head = l.tail = nullptr;
    }
    // Root is the leaf node
    else if(!root->left and !root->right){
        l.tail = l.head = root;
    }
    // No Right Child
    else if (!root->right){
        LinkedList leftLL = flattenBST(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    // No Left Child
    else if(!root->left){
        LinkedList rightLL = flattenBST(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    // Both Children exists
    else{
        LinkedList leftLL = flattenBST(root->left);
        LinkedList rightLL = flattenBST(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

int main() {
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = nullptr;
    for (auto x: arr) {
        root = createBST(root, x);
    }
    LinkedList l = flattenBST(root);
    Node *temp = l.head;
    while(temp){
        cout << temp->val << " --> ";
        temp = temp->right;
    }
    cout << endl;
    return 0;
}
