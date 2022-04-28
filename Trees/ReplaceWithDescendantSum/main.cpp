#include <iostream>
#include <vector>
#include <queue>
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

int descendantSum(Node *root){
    if(root == nullptr) return 0;

    if(root->left == nullptr and root->right == nullptr)
        return root->val;

    int leftSum = descendantSum(root->left);
    int rightSum = descendantSum(root->right);

    int temp = root->val;
    root->val = leftSum + rightSum;
    return root->val + temp;
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
    cout<<endl;
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BuildTree(arr);
    levelOrder(root);
    descendantSum(root);
    levelOrder(root);


    return 0;
}
