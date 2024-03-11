#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> pre;
vector<int> inorder;

void printPost(int preStart, int preEnd, int inorderStart, int inorderEnd) {
    if (preStart > preEnd) return;
    
    if (preStart == preEnd) {
        cout << pre[preStart] << " ";
        return;
    }

    int root = pre[preStart];
    int rootIdxInInorder = find(all(inorder), root) - inorder.begin();
    int lSize = rootIdxInInorder - inorderStart;
    int rSize = inorderEnd - rootIdxInInorder;

    printPost(preStart+1, preStart+lSize, inorderStart, inorderStart+rootIdxInInorder-1);
    printPost(preStart+lSize+1, preEnd, inorderStart+lSize+1, inorderEnd);
    cout << root << " ";
    return;
}

int main() {
    int c; cin >> c;
    while(c--) {
        int n; cin >> n; pre.resize(n); inorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> pre[i];
        for (int i = 0; i < n; ++i) cin >> inorder[i];
        printPost(0, n-1, 0, n-1);
        cout << endl;
    }
}