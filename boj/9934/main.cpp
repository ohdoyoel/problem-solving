#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int k;
vector<int> A;
vector<vector<int>> tree;

void fillTree(int start, int end, int depth) {
    if (depth == k) return;

    int mid = (start+end)/2;
    tree[depth].push_back(A[mid]);
    
    fillTree(start, mid, depth+1);
    fillTree(mid+1, end, depth+1);
}

void printTree() {
    for (vector<int> level : tree) {
        for (int child : level) cout << child << " ";
        cout << endl;
    }
}

int main() {
    cin >> k; A.resize(pow(2, k)-1); tree.resize(k);
    for (int i=0; i<sz(A); i++) cin >> A[i];
    fillTree(0, sz(A), 0);
    printTree();
}