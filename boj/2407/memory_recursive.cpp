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

lld comb(vector<vector<lld>> &table, int i, int j)
{
    if (table[i][j] != 0) return table[i][j];
    if (j == 0 || j == i) return (table[i][j] = 1);
    return (table[i][j] = comb(table, i - 1, j - 1) + comb(table, i - 1, j));
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;
    vector<vector<lld>> table (n + 1, vector<lld>(m + 1, 0));

    // algorithm
    ///////////////////////////////////////

    // output
    ///////////////////////////////////////
    cout << comb (table, n, m) << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/