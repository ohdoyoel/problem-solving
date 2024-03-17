#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node {
    int value;
    Node* parent;
    vector<Node*> children;
};

vector<Node*> nodes;

int main() {
    int n; cin >> n;nodes.resize(n+1);

    for (int i=1; i<n; i++) nodes[i]->value = i;
    
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y;
        
        if (x == 1 || nodes[x]->parent != NULL) {
            nodes[x]->children.push_back(nodes[y]);
            nodes[y]->parent = nodes[x];
        } else if (y == 1 || nodes[y]->parent != NULL) {
            nodes[y]->children.push_back(nodes[x]);
            nodes[x]->parent = nodes[y];
        }
    }

    for (int i=2; i<=n; i++) cout << nodes[i]->value << endl;
}