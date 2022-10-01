#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
#define MAX 1e7

// variable
///////////////////////////////////////
int n;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    vector<int> dp(n + 1, MAX);

    // algorithm
    ///////////////////////////////////////
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + 1);
        if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);
    }
    
    // output
    ///////////////////////////////////////
    int res = dp[n];
    if (res != MAX) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/