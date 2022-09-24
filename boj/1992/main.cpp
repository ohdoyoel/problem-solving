#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n;
vector<char> ans;

void solve(vector<vector<uint>> &table, uint n, uint x, uint y)
{
    if (n == 1)
    {
        ans.push_back(table[x][y] + '0');
        return;
    }
    bool flag = true;
    for (uint i = x; i < x + n; i++)
    {
        for (uint j = y; j < y + n; j++)
        {
            if (table[x][y] != table[i][j])
            {
                flag = false; 
                break;
            }
        }
    }
    if (flag)
    {
        ans.push_back(table[x][y] + '0');
        return ;
    }
    ans.push_back('(');
    solve(table, n / 2, x, y);
    solve(table, n / 2, x, y + n / 2);
    solve(table, n / 2, x + n / 2, y);
    solve(table, n / 2, x + n / 2, y + n / 2);
    ans.push_back(')');
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    vector<vector<uint>> table(n, vector<uint>(n));

    for (uint i = 0; i < table.size(); i++)
    {
        string input;
        cin >> input;
        for (uint j = 0; j < table[0].size(); j++)
        {
            table[i][j] = input[j] - '0';
        }
    }

    //////////////////////////////////////////////

    solve(table, n, 0, 0);

    //////////////////////////////////////////////

    for (uint i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;

    return 0;
}