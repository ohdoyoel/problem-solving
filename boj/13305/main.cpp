#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> P, D;

long long solve(int n) {
    long long ret = 0;
    long long minP = 9876543210;
    for (int i=0; i<n; ++i) {
        if (P[i] < minP) minP = P[i];
        ret += minP * D[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; n--; P.resize(n); D.resize(n);
    for (int i=0; i<n; ++i) cin >> D[i];
    for (int i=0; i<n; ++i) cin >> P[i];
    cout << solve(n) << endl;
}