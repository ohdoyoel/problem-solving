#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1002];
int n;
vector<int> A;
vector<int> B;

int lis(int i) {
    int& ret = cache[i+1];
    if (ret!=-1) return ret;

    ret = 1;
    int lisIndex = -1;
    for (int j=i+1; j<n; j++) {
        int cand = 1+lis(j);
        if (A[j]>A[i] && cand > ret) {
            ret = cand;
            lisIndex = j;
        }
    }
    if (lisIndex!=-1) B.push_back(lisIndex);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n; A.resize(n);
    for (int i=0; i<n; i++) cin >> A[i];
    cout << lis(-1) << endl;
    for (int b: B) cout << b << endl;
}