#include<bits/stdc++.h>
#define endl "\n"
#define sz(X) (uint)(x).size()
using namespace std;

int cache[100001];

int solve(int n) {
    int &ret = cache[n];
    if (ret != -1) return ret;
    
    if (n == 0) return 1;
    else if (n == 1) return ret = 3;
    else if (n == 2) return ret = 7;

    ret = solve(1) * solve(n - 1);
    
    int res = 0; bool flag = true;
    for (int i = n - 2; i >= 0; --i) {
        if (flag) res += solve(i);
        else res -= solve(i);
        flag = !flag;
    }
    ret -= 2 * res;
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(n) << endl;
}