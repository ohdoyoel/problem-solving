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
vector<vector<int>> table;
bool visited[1001] = {0,};
int cnt = 0;

void dfs(int k)
{
    visited[k] = true;
    for (auto i = table[k].begin(); i != table[k].end(); i++)
    {
        if (!visited[*i]) dfs(*i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;
    table = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        table[x].push_back(y);
        table[y].push_back(x);
    }

    // algorithm
    ///////////////////////////////////////
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }

    // output
    ///////////////////////////////////////
    cout << cnt << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/