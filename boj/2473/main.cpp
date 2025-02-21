#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A, ANS;

void solve() {
    ANS = {-1, -1, -1};
    sort(A.begin(), A.end());

    int lo=0, hi=n-1;
    int min = 2000000001;
    for (int i=0; i<n; ++i) {
        while(lo<hi) {
            if (lo==i) { lo++; continue; }
            if (hi==i) { hi--; continue; }

            int sum = A[lo] + A[hi] + A[i];
            if (abs(sum) < min) {
                min = abs(sum);
                ANS = { A[lo], A[hi], A[i] };
            }

            if (sum > 0) lo++;
            else if (sum < 0) hi--;
            else return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    solve();
    for (int a : ANS) cout << a << " ";
    cout << endl;
}