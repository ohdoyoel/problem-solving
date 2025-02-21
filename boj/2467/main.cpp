#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;

pair<int,int> solve() {
    sort(A.begin(), A.end());
    pair<int, int> ans;
    
    int lo=0, hi=n-1;
    int min = 2000000001;
    while (lo<hi) {
        int sum = A[lo] + A[hi];
        if (abs(sum) < min) {
            min = abs(sum);
            ans = {A[lo], A[hi]};
        }
        if (sum > 0) hi--;
        else if (sum < 0) lo++;
        else break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    auto [l, h] = solve();
    cout << l << " " << h << endl;
}