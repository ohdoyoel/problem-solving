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

    // algorithm
    ///////////////////////////////////////
    int ans = MAX;
    for (int i = 0; i <= n / 5; i++)
    {
        if ((n - 5 * i) % 3 == 0) ans = min(ans, i + (n - 5 * i) / 3);
    }

    // output
    ///////////////////////////////////////
    if (ans != MAX) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/