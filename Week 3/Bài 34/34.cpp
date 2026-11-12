#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int id;
    vector<Node*> child;
    Node(int val) {
        id = val;
    }
};
Node *root;
Node * find(Node * root, int id) {
    if(root == nullptr) return nullptr;
    if(root->id == id) return root;
    for(Node *child : root->child) {
        Node *result = find(child, id);
        if(result != nullptr) return result;
    }
    return nullptr;
}
void preOrder(Node *root) {
    if(root == nullptr) return;
    cout << root->id << ' ';
    for(Node * child : root->child) preOrder(child);
}
void inOrder(Node *root) {
    if(root == nullptr) return;
    if(!root->child.empty()) inOrder(root->child[0]);
    cout << root->id << ' ';
    for(Node * child : root->child) {
        if(child != root->child[0]) inOrder(child);
    }
}
void postOrder(Node *root) {
    if(root == nullptr) return;
    for(Node * child : root->child) postOrder(child);
    cout << root->id << ' ';
}
int main() {
    int a, b;
    string s;
    while(1) {
        cin >> s;
        if(s == "*") return 0;
        if(s == "MakeRoot") { 
            cin >> a;
            root = new Node(a);
        } else if(s == "Insert") {
            cin >> a >> b;
            Node * u = find(root, b);
            Node* newNode = new Node(a);
            u->child.push_back(newNode);
        }
        else if(s == "PreOrder") {
            preOrder(root);
            cout << endl;
        }
        else if(s == "InOrder") {
            inOrder(root);
            cout << endl;
        }
        else {
            postOrder(root);
            cout << endl;
        }
    }
}
