#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n; 
vector<int> A;

bool good(int i) {
    int lo=0, hi=n-1;
    while(lo<hi) {
        if (lo==i) { lo++; continue; }
        if (hi==i) { hi--; continue; }
        int sum = A[lo]+A[hi];
        if (sum > A[i]) hi--;
        else if (sum < A[i]) lo++;
        else return true;
    }
    return false;
}

int solve() {
    int res = 0;
    for (int i=0; i<n; ++i) if (good(i)) res++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    cout << solve() << endl;
}