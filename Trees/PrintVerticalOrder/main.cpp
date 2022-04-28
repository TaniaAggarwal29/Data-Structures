#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int d){
        val = d;
        left = right = nullptr;
    }
};

void verticalOrder(Node *root, int k, map<int, vector<int>> &m){
    if(!root)
        return;
    m[k].push_back(root->val);
    verticalOrder(root->left, k-1, m);
    verticalOrder(root->right, k+1, m);
}

int main() {
    map<int, vector<int>> m;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    verticalOrder(root, 0, m);
    for(auto [f, s]: m){
        for(auto x: s){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
