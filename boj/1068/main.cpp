#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> parents;
struct node {
    int value;
    node* parent;
    vector<node*> children;
    node(int v) : value(v) {}
};

int e;
node* getTreeWithoutE(int root) {
    node* ret = new node(root);
    for (int i=0; i<parents.size(); i++) {
        if (root != e && i != e && parents[i] == root) ret->children.push_back(getTreeWithoutE(i));
    }
    return ret;
}

int countLeaf(node* tree) {
    if (tree->children.empty()) return (tree->value != 0);
    int ret = 0;
    for (auto child : tree->children) ret += countLeaf(child);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; parents.resize(n);
    int t = n; int root;
    for (int i=0; i<n; i++) {
        int p; cin >> p;
        if (p == -1) root = i;
        parents[i] = p;
    }
    cin >> e;
    node* tree = getTreeWithoutE(root);

    cout << countLeaf(tree) << endl;
}