#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

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
    vector<int> dp(n + 1);

    // algorithm
    ///////////////////////////////////////
    for (int i = 1; i < sz(dp); i++)
    {
        if (i == 1) dp[i] = 100;
        else if (i == 2) dp[i] = 100;
        else if (i == 3) dp[i] = 1;
        else if (i == 5) dp[i] = 1;
        
        if (i % 5 == 0) dp[i] = min(dp[i], i / 5);
        if (i % 3 == 0) dp[i] = min(dp[i], i / 3);
        dp[i] = min(dp[i], dp[i - 3] + 1);
        dp[i] = min(dp[i], dp[i - 5] + 1);
    }
    

    // output
    ///////////////////////////////////////
    for (int i = 0; i < sz(dp); i++) cout << dp[i] << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/