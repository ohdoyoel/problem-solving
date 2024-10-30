#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[502];
int n;
vector<int> A, sortedA;

int lis(int i) {
    if (i==n) return 0;

    int& ret = cache[i+1];
    if (ret!=-1) return ret;

    ret = 1;
    for (int j=i+1; j<n; ++j) if (i==-1 || A[j]>A[i]) ret = max(ret, 1+lis(j));
    return ret;
}

int numLis(int i) {
    if (i==n-1) return 1;
    int ret = 1;
    for (int j=i+1; j<n; ++j) if (A[j]>A[i]) ret += numLis(j);
    return ret;
}

void kthLis(int k, int l) {
    int sub = 0;
    for (int i=0; i<n; ++i) {
        int idx = 0;
        for (int j=0; j<n; ++j) {
            if (A[j]==A[i]) {
                idx = j;
                return;
            }
        }
        if (k<numLis(idx)) {
            cout << sortedA[i] << ' ';
            kthLis(k-sub, l-1);
        } else sub += numLis(idx);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        memset(cache, =1, sizeof(cache));
        int n, k; cin >> n >> k; A.resize(n);
        for (int i=0; i<n; ++i) cin >> A[i];
        sortedA = A;
        sort(A.begin(), A.end());
        int l = lis(-1) - 1;
        cout << l << endl;
        kthLis(k, l);
    }
}