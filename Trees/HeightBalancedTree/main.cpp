// Height Balanced Tree -- if left subtree and right subtree has max height difference of 1

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

class HeightBalance{
public:
    int height;
    bool balanced;

    HeightBalance(){
        height=0;
        balanced= false;
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

HeightBalance heightBalancedTree(Node *root){
    HeightBalance h;
    if(root == nullptr){
        h.height = 0;
        h.balanced = true;
        return h;
    }

    HeightBalance Left = heightBalancedTree(root->left);
    HeightBalance Right = heightBalancedTree(root->right);

    h.height = max(Left.height, Right.height)+1;
    h.balanced = Left.balanced and Right.balanced and (abs(Left.height-Right.height)<=1);

    return h;
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BuildTree(arr);

    HeightBalance h = heightBalancedTree(root);
    cout << h.balanced << endl;
    return 0;
}
