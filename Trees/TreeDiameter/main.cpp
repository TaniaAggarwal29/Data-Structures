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

int height(Node* root) {
    if(root == nullptr)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}

int treeDiameter(Node* root){
    if(root == nullptr) return 0;

    int d1 = height(root->left) + height(root->right);
    int d2 = treeDiameter(root->left);
    int d3 = treeDiameter(root->right);
    return max(d1, max(d2, d3));
}

// Optimized code for tree diameter
class HD{
public:
    int height, diameter;
};

HD optTreeDiameter(Node *root){
    HD p;
    if(root == nullptr){
        p.height = p.diameter = 0;
        return p;
    }
    HD Left = optTreeDiameter(root->left);
    HD Right = optTreeDiameter(root->right);
    p.height = 1 + max(Left.height, Right.height);

    int d1 = Left.height + Right.height;
    int d2 = Left.diameter;
    int d3 = Right.diameter;

    p.diameter = max(d1, max(d2, d3));
    return p;
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BuildTree(arr);
    cout << treeDiameter(root) << endl;

    HD p = optTreeDiameter(root);
    cout << p.diameter << endl;
    return 0;
}
