#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1001];
int n;
vector<int> A;

int lis(int i) {
    int& ret = cache[i];
    if (ret!=-1) return ret;

    int ret = 0;
    for (int j=0; j<n; j++) if (A[j]>A[i]) ret = max(ret, 1+lis(j));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n; A.resize(n);
    for (int i=0; i<n; i++) cin >> A[i];
    cout << lis(0) << endl;

    return 0;
}