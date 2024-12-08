#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> PRE;
vector<int> IOD;

// PRE의 index를 받음
void printPost(int sp, int ep, int si, int ei) {
    if (sp==ep) return;
    else if (ep-sp==1) {
        cout << PRE[sp] << " ";
        return;
    }

    int root = PRE[sp];
    int rootIdxIOD;
    for (rootIdxIOD=si; rootIdxIOD<ei; ++rootIdxIOD) if (IOD[rootIdxIOD]==root) break;
    
    int sizeLT = rootIdxIOD - si;
    int sizeRT = ei-rootIdxIOD-1;

    printPost(sp+1, sp+1+sizeLT, si, si+sizeLT);
    printPost(sp+1+sizeLT, e, si+sizeLT+1, ei);
    cout << root << " "
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        int n; cin >> n; PRE.resize(n); IOD.resize(n);
        printPost(0, n);
    }
}