#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, c;
vector<int> A;

int solve() {
    int lo=0, hi=1000000001;
    int mid;
    while (lo < hi-1) {
        mid = (lo+hi) / 2;

        int cnt = 1;
        int lastEnd = A[0];
        for (int i=1; i<n; ++i) {
            if (A[i]>= lastEnd + mid) {
                lastEnd = A[i];
                cnt++;
            }
        }

        if (cnt >= c) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    cout << solve() << endl;
}