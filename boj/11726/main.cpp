#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int cache[1001] = {0};

lld sol(int n) {
    int& ret = cache[n];
    if (ret != 0) return ret;
    
    if (n == 0) return ret= 0;
    else if (n == 1) return ret = 1;
    else if (n == 2) return ret = 2;
    
    return ret = sol(n - 2) + sol(n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << sol(n) << endl;

    return 0;
}