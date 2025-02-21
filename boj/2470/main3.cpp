#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;

int solve() {
    pair<int, int> ret;    

    int min = 987654321;
    int lo=0, hi=n-1;
    while (lo<hi) {
        int sum = A[lo] + A[hi];

        if (abs(sum) < min) {
            min = abs(sum);
            ans = {A[lo], A[hi]};
        }

        if (sum < 0) lo++;
        else if (sum > 0) hi--;
        else break;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.assign(n, 0);
    for (int i=0; i<n; ++i) cin >> A[i];
    cout << solve() << endl;
}