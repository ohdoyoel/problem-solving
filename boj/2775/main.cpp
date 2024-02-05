#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[15][15] = {0,};

int num(int i, int j) {
    int& ret = cache[i][j];
    if (ret != 0) return ret;
    
    int sum = 0;
    if (i == 0) return ret = j;
    else {
        for (int k = 0; k <= j; ++k) {
            sum += num(i - 1, k);
        }
        return ret = sum;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << num(a, b) << endl;
    }

    return 0;
}