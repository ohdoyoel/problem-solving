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
uint m, n;
uint min_diff, diff;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    
    cin >> n >> m;
    vector<vector<char>> table(n, vector<char>(m));
    vector<vector<char>> table_w(8, vector<char>(8));
    vector<vector<char>> table_b(8, vector<char>(8));

    for (uint i = 0; i < n; i++)
    {
        for (uint j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    // algorithm
    ///////////////////////////////////////

    for (uint i = 0; i < 8; i++)
    {
        for (uint j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0) table_w[i][j] = 'W';
            else table_w[i][j] = 'B';
        }
    }

    for (uint i = 0; i < 8; i++)
    {
        for (uint j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0) table_b[i][j] = 'B';
            else table_b[i][j] = 'W';
        }
    }

    min_diff = 65;

    for (uint x = 0; x <= n - 8; x++)
    {
        for (uint y = 0; y <= m - 8; y++)
        {
            diff = 0;
            for (uint i = 0; i < 8; i++)
            {
                for (uint j = 0; j < 8; j++)
                {
                    if (table[i + x][j + y] != table_w[i][j]) diff++;
                }
            }
            if (diff < min_diff) min_diff = diff;
        }
    }

    for (uint x = 0; x <= n - 8; x++)
    {
        for (uint y = 0; y <= m - 8; y++)
        {
            diff = 0;
            for (uint i = 0; i < 8; i++)
            {
                for (uint j = 0; j < 8; j++)
                {
                    if (table[i + x][j + y] != table_b[i][j]) diff++;
                }
            }
            if (diff < min_diff) min_diff = diff;
        }
    }

    // output
    ///////////////////////////////////////

    cout << min_diff << endl;

    return 0;
}