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
vector<vector<int>> table;
int color[20001];
bool ans;

void dfs(int k, int c, bool& ans)
{
    color[k] = c;
    int c_rev = (c == 1) ? 2 : 1;

    for (auto i = table[k].begin(); i != table[k].end(); i++)
    {
        if (color[*i] == c) ans = false;
        else if (color[*i] == 0) dfs(*i, c_rev, ans);
    }
}

void solve(int v, int e)
{
    fill_n(color, 20001, 0);

    ans = true;
    table = vector<vector<int>>(v + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        table[x].push_back(y);
        table[y].push_back(x);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!color[i]) dfs(i, 1, ans);
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v, e;
        cin >> v >> e;
        solve(v, e);
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