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
int res = 0;
vector<vector<int>> table;

int cap()
{
    int _cap = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 0)
            {
                _cap++;
            }
        }
    }
    return _cap;
}

void solve(int cnt)
{
    if (cnt == n)
    {
        res++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 0)
            {
                vector<vector<int>> temp = table;
                table[i][j] = 1;
                for (int x = 0; x < n; x++)
                {
                    table[i][x] = 1;
                    table[x][j] = 1;
                }
                for (int x = i; x < n; x++)
                {
                    for (int y = j; y < n; y++)
                    {
                        table[x][y] = 1;
                    }
                    for (int y = j; y >= 0; y--)
                    {
                        table[x][y] = 1;
                    }
                }
                for (int x = i; x >= 0; x--)
                {
                    for (int y = j; y < n; y++)
                    {
                        table[x][y] = 1;
                    }
                    for (int y = j; y >= 0; y--)
                    {
                        table[x][y] = 1;
                    }
                }
                solve(cnt + 1);
                table = temp;
                solve(cnt);
            }
        }
    }
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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        table.push_back(v);
    }
    solve(0);
    
    // output
    ///////////////////////////////////////
    cout << res << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/