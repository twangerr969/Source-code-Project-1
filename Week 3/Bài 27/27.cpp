#include<iostream>
#include<sstream>
using namespace std;
struct Node {
    int val;
    Node * left;
    Node * right;
    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
Node * root;
void insert(Node *& root, int value) {
    if(root == nullptr) {
        Node * newNode = new Node(value);
        root = newNode;
        return;
    }
    if(value < root->val) insert(root->left, value);
    else if(value > root->val) insert(root->right, value);
    else return;
}
void preOrder(Node * root) {
    if(root == nullptr) return;
    cout << root->val << ' ';
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
    string s, s1;
    int x;
    while(getline(cin, s)) {
        if(s == "#") break;
        stringstream ss(s);
        ss >> s1 >> x;
        insert(root, x);
    }
    preOrder(root);
    return 0;
}
