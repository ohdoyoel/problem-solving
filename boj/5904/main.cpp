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
uint n, k;

uint moo_len(uint i)
{
    if (i == 0) return 3;
    return 2 * moo_len(i - 1) + i + 3;
}

char solve(uint n, uint k)
{
    uint l = (k > 0) ? moo_len(k - 1) : 0;
    uint r = (k > 0) ? moo_len(k) - l : 2;
    if (n > l && n <= r) return (n == l + 1) ? 'm' : 'o';
    else if (n <= l) return solve(n, k - 1);
    else if (n > r) return solve(n - r, k - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;

    // algorithm
    ///////////////////////////////////////
    uint i = 0;
    while (true)
    {
        // cout << i << ' ' << moo_len(i) << endl;
        if (n <= moo_len(i)) break;
        i++;
    }

    // output
    ///////////////////////////////////////

    cout << solve(n, i) << endl;

    return 0;
}