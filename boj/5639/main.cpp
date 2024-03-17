#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> pre;

void printPost(int preStart, int preEnd) {
    if (preStart > preEnd) return;
    int lStart = preStart+1;
    int rStart = lStart;
    for (int i=lStart; i<preEnd; i++) {
        if (pre[i] > pre[preStart]) rStart = i;
    }
    printPost(lStart, rStart-1);
    printPost(rStart, preEnd);
    cout << pre[preStart] << endl;
    return;
}

int main() {
    int n;
    while(cin >> n) pre.push_back(n);
    printPost(0, pre.size()-1);
}