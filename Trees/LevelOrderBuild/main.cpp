#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int d){
        val = d;
        left = right = nullptr;
    }
};

Node* BuildTree(vector<int> arr){
    queue<Node*> q;
    Node *root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    while(!q.empty()){
        Node *n = q.front();
        q.pop();
        if(arr[i] !=-1){
            n->left = new Node(arr[i]);
            q.push(n->left);
        }
        i++;
        if(arr[i] !=-1){
            n->right = new Node(arr[i]);
            q.push(n->right);
        }
        i++;
    }
    return root;
}

void levelOrder(Node* root){
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        if(n == nullptr){
            if(q.empty()) break;
            q.push(nullptr);
            cout << endl;
        }
        else {
            cout << n->val << " ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
    Node *root = BuildTree(arr);
    levelOrder(root);
    return 0;
}
