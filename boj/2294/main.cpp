#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

const int inf = 987654321;
int dp[10001];
vector<int> coins;

int main() {
    int n, k;
    cin >> n >> k;
    coins.resize(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 0; i < 10001; i++) dp[i] = inf;

    dp[0] = 0;
    for (int p = 1; p <= k; p++) for (int coin : coins) if (p >= coin) dp[p] = min(dp[p], 1 + dp[p - coin]);
    
    int res = (dp[k] == inf) ? -1 : dp[k];
    cout << res  << endl;
}