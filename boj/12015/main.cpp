#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;
vector<int> ANS;

int searchIdx(int k) {
    int lo=0, hi=ANS.size()-1;
    int mid;
    while(lo<hi-1) {
        mid = (lo+hi) / 2;
        if (ANS[mid] >= k) hi = mid;
        else lo = mid;
    }
    return hi;
}

int solve() {
    ANS = { A[0] };
    for (int i=1; i<n; ++i) {
        if (A[i]>ANS.back()) ANS.push_back(A[i]);
        else {
            int idx = searchIdx(A[i]);
            ANS[idx] = A[i];
        }
    }
    return ANS.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    cout << solve() << endl;
}