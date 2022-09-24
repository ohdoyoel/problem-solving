#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int n, r, c;

int ans = 0;
void solve(int n, uint x, uint y, uint r, uint c)
{
    //cout << n << " " << x << " " << y << " " << r << " " << c << " " << ans << endl;
    if (n == 0)
    {
        return ;
    }
    int p = pow(2, n - 1);
    if (r < p && c < p)
    {
        ans += 0;
        solve(n - 1, 0, 0, r, c);
    }
    else if (r < p && c >= p)
    {
        ans += pow(2, 2 * n - 2);
        solve(n - 1, 0, p, r, c - p);
    }
    else if (r >= p && c < p)
    {
        ans += 2 * pow(2, 2 * n - 2);
        solve(n - 1, p, 0, r - p, c);
    }
    else if (r >= p && c >= p)
    {
        ans += 3 * pow(2, 2 * n - 2);
        solve(n - 1, p, p, r - p, c - p);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> r >> c;

    solve(n, 0, 0, r, c);
    cout << ans << endl;

    return 0;
}