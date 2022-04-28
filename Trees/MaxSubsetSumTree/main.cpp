#include <iostream>
#include <vector>
using namespace std;

struct Node{
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

pair<int, int> maxSum(Node *root) {
    if(root == nullptr)
        return {0, 0};

    pair<int, int> Left = maxSum(root->left);
    pair<int, int> Right = maxSum(root->right);

    int include = root->val + Left.second + Right.second;
    int exclude = max(Left.first, Left.second) + max(Right.first, Right.second);
    return {include, exclude};
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BuildTree(arr);
    pair<int, int> p = maxSum(root);
    cout << max(p.first, p.second) << endl;
    return 0;
}
