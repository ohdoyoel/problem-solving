#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> pre;
vector<int> in;

void printPost(int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart>=preEnd || inStart>=inEnd) return;
    
    int root = pre[preStart];

    int rootIdxIn = inStart;
    for (int cand=inStart; cand<inEnd; cand++) {
        if (in[cand] == root) {
            rootIdxIn = cand;
            break;
        }
    }

    int leftInStart = inStart; int leftInEnd = rootIdxIn;
    int rightInStart = rootIdxIn+1; int rightInEnd = inEnd;

    int leftSize = leftInEnd-leftInStart; int rightSize = rightInEnd-rightInStart;

    int leftPreStart = preStart+1; int leftPreEnd = leftPreStart+leftSize;
    int rightPreStart = leftPreEnd; int rightPreEnd = rightPreStart+rightSize;

    printPost(leftPreStart, leftPreEnd, leftInStart, leftInEnd);
    printPost(rightPreStart, rightPreEnd, rightInStart, rightInEnd);
    cout << root << ' ';
}

int main() {
    int c; cin >> c;
    while(c--) {
        int n; cin >> n; pre.resize(n); in.resize(n);
        for (int i=0; i<n; i++) cin >> pre[i];
        for (int i=0; i<n; i++) cin >> in[i];
        printPost(0, n, 0, n);
        cout << endl;
    }
}