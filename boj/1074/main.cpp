#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n, r, c;

int ans = 0;
int solve(uint n, uint r, uint c, uint x, uint y)
{
    if (n == 1) return ans;
    if (r <)
    fill_table(table, n - 1, r, c);
    fill_table(table, n - 1, r, c + pow(2, n - 1));
    fill_table(table, n - 1, r + pow(2, n - 1), c);
    fill_table(table, n - 1, r + pow(2, n - 1), c + pow(2, n - 1));
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> r >> c;

    cout << solve(n, r, c) << endl;

    return 0;
}