#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n, r, c;

int e = 0;
void fill_table(vector<vector<int>> &table, uint n, uint r, uint c)
{
    if (n == 1)
    {
        table[r][c] = e++;
        table[r][c + 1] = e++;
        table[r + 1][c] = e++;
        table[r + 1][c + 1] = e++;
        return ;
    }
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
    vector<vector<int>> table(pow(2, n), vector<int>(pow(2, n)));

    fill_table(table, n, 0, 0);

    cout << table[r][c] << endl;

    return 0;
}