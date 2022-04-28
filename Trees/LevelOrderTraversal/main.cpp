#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int d){
        val = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* BuildTree(){
    int d;
    cin >> d;

    if (d==-1)
        return nullptr;

    Node* n = new Node(d);
    n->left = BuildTree();
    n->right = BuildTree();

    return n;
}

vector<int> levelOrderTraversal(Node* root) {
    if(root == nullptr) return {};

    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        ans.push_back(n->val);
        if (n->left)
            q.push(n->left);
        if (n->right)
            q.push(n->right);
    }
    return ans;
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
    Node* root = BuildTree();
    vector<int> ans = levelOrderTraversal(root);

    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
    levelOrder(root);

    return 0;
}

//             1
//           /   \
//          2     3
//         / \     \
//        4   5     6
//            /
//           7

// input: 1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1