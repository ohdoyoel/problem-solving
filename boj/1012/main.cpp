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
int t;
int m, n, k;
vector<vector<bool>> table;
int ans;

void dfs(int _i, int _j)
{
    if (table[_i][_j]) table[_i][_j] = false;
    else return;
    
    if (_i > 0) dfs(_i - 1, _j);
    if (_i < m - 1) dfs(_i + 1, _j);
    if (_j > 0) dfs(_i, _j - 1);
    if (_j < n - 1) dfs(_i, _j + 1);
}

void solve(int _m, int _n, int _k)
{
    table = vector<vector<bool>>(_m, vector<bool>(_n, false));
    ans = 0;
    for (int i = 0; i < _k; i++)
    {
        int x, y;
        cin >> x >> y;
        table[x][y] = true;
    }
    for (int i = 0; i < _m; i++)
    {
        for (int j = 0; j < _n; j++)
        {
            if (table[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> k;
        solve(m, n, k);
    }

    // algorithm
    ///////////////////////////////////////
    

    // output
    ///////////////////////////////////////
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/