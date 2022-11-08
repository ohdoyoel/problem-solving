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
int n, m;
int x, y;
vector<vector<int>> table;
bool visited[101] = {0,};
bool found = false;
int ans;

void dfs(int k, int d)
{
    visited[k] = true;
    if (found) return;
    if (k == y)
    {
        found = true;
        ans = d;
        return;
    }
    for (auto i = table[k].begin(); i != table[k].end(); i++)
    {
        if(!visited[*i]) dfs(*i, d + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    cin >> x >> y;
    cin >> m;

    table = vector<vector<int>>(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        table[a].push_back(b);
        table[b].push_back(a);
    }

    // algorithm
    ///////////////////////////////////////
    dfs(x, 0);

    // output
    ///////////////////////////////////////
    if (ans == 0) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/