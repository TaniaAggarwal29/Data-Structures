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

int closestInBST(Node *root, int target){
    int closest=0;
    int min_diff = INT_MAX;
    Node *temp = root;
    while(temp){
        int curr_diff = abs(temp->val - target);

        if(curr_diff == 0) return temp->val;

        if(curr_diff < min_diff){
            min_diff = curr_diff;
            closest = temp->val;
        }

        if(target < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return closest;
}

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

int main() {
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    Node *root = nullptr;
    for (auto x: arr) {
        root = createBST(root, x);
    }
    cout << closestInBST(root, 12) << endl;
    cout << closestInBST(root, 16) << endl;
    return 0;
}
