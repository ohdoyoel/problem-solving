#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<pair<int,int>> A;
vector<int> IN;

int solve() {
    sort(A.begin(), A.end());
    
    for (int i=0; i<n-1; ++i) {
        auto [x, h] = A[i];
        for (int j=i+1; j<n; j++) {
            auto [_x, _h] = A[j];
            if (_x-_h<=x && x<_x) IN[i]++;
            else if (x<_x && _x<=x+h) IN[j]++;
        }
    }
    
    int ret = 0;
    for (int i=0; i<n; ++i) if (IN[i]==0) ret++;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n); IN.assign(n, 0);

    for (int i=0; i<n; ++i) {
        int x, h; cin >> x >> h;
        A[i] = {x, h};
    }


    cout << solve() << endl;
}