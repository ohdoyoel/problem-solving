#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node {
    int key;
    int priority, size;
    Node *left, *right;
    Node(const int& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) { left=newLeft; calcSize(); }
    void setRight(Node* newRight) { right=newRight; calcSize(); }
    void calcSize() { size=1; if(left) size+=left->size; if(right) size+=right->size;}
};

typedef pair<Node*,Node*> NodePair;

NodePair split(Node* root, int key) {
    if (root == NULL) return NodePair(NULL, NULL);
    if (root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first); node->setRight(splitted.second);
        return node;
    }
    if (root->key < node->key) root->setRight(insert(root->right, node));
    else root->setLeft(insert(root->left, node));
    return root;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

Node* erase(Node* root, int key) {
    if (root == NULL) return root;
    if (root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (root->key < key) root->setRight(erase(root->right, key));
    else root->setLeft(erase(root->left, key));
    return root;
}

Node* kth(Node* root, int k) {
    int leftSize = root->left ? root->left->size : 0;
    if (k <= leftSize) return kth(root->left, k);
    if (k == leftSize+1) return root;
    return kth(root->right, k-leftSize-1);
}

int n;
vector<int> shifted;
vector<int> A;

void solve() {
    Node* candidates = NULL;
    for (int i=1; i<=n; i++) candidates = insert(candidates, new Node(i));
    for (int i=n-1; i>=0; i--) {
        Node* k = kth(candidates, i + 1 - shifted[i]);
        A[i] = k->key;
        candidates = erase(candidates, k->key);
    }
}

int main() {
    int c; cin >> c;
    while(c--) {
        cin >> n; shifted.resize(n); A.resize(n);
        for (int i=0; i<n; i++) cin >> shifted[i];
        solve();
        for (int a : A) cout << a << " ";
        cout << endl;
    }
}