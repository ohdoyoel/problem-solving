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
uint k;
uint x, y;

// table에서 2^k 만큼의 정사각형을 (x0, y0)에서 부터 탐색할 것, (x, y)는 배수구의 상대 위치
uint e = 1;
void solve(vector<vector<int>> &table, uint n, uint x0, uint y0, uint x, uint y)
{
    uint p_n = pow(2, n);
    if (n == 1)
    {
        for (uint r = x0; r < x0 + p_n; r++)
        {
            for (uint c = y0; c < y0 + p_n; c++)
            {
                if (r != (x0 + x) || c != (y0 + y)) table[r][c] = e;
            }
        }
        e++;
        return;
    }
    uint p_n_minus_one = pow(2, n - 1);
    if (x < p_n_minus_one && y < p_n_minus_one)
    {
        table[x0 + p_n_minus_one][y0 + p_n_minus_one - 1] = e;
        table[x0 + p_n_minus_one - 1][y0 + p_n_minus_one] = e;
        table[x0 + p_n_minus_one][y0 + p_n_minus_one] = e;
        e++;
        solve(table, n - 1, x0, y0, x - x0, y - y0);
        solve(table, n - 1, x0 + p_n_minus_one, y0, 0, p_n_minus_one - 1);
        solve(table, n - 1, x0, y0 + p_n_minus_one, p_n_minus_one - 1, 0);
        solve(table, n - 1, x0 + p_n_minus_one, y0 + p_n_minus_one, 0, 0);
    }
    else if (x >= p_n_minus_one && y < p_n_minus_one)
    {
        table[x0 + p_n_minus_one - 1][y0 + p_n_minus_one - 1] = e;
        table[x0 + p_n_minus_one - 1][y0 + p_n_minus_one] = e;
        table[x0 + p_n_minus_one][y0 + p_n_minus_one] = e;
        e++;
        solve(table, n - 1, x0, y0, p_n_minus_one - 1, p_n_minus_one - 1);
        solve(table, n - 1, x0 + p_n_minus_one, y0, x - x0, y -y0);
        solve(table, n - 1, x0, y0 + p_n_minus_one, p_n_minus_one - 1, 0);
        solve(table, n - 1, x0 + p_n_minus_one, y0 + p_n_minus_one, 0, 0);
    }
    else if (x < p_n_minus_one && y >= p_n_minus_one)
    {
        table[x0 + p_n_minus_one - 1][y0 + p_n_minus_one - 1] = e;
        table[x0 + p_n_minus_one][y0 + p_n_minus_one - 1] = e;
        table[x0 + p_n_minus_one][y0 + p_n_minus_one] = e;
        e++;
        solve(table, n - 1, x0, y0, p_n_minus_one - 1, p_n_minus_one - 1);
        solve(table, n - 1, x0 + p_n_minus_one, y0, 0, p_n_minus_one - 1);
        solve(table, n - 1, x0, y0 + p_n_minus_one, x - x0, y - y0);
        solve(table, n - 1, x0 + p_n_minus_one, y0 + p_n_minus_one, 0, 0);
    }
    else if (x >= p_n_minus_one && y >= p_n_minus_one)
    {
        table[x0 + p_n_minus_one - 1][y0 + p_n_minus_one - 1] = e;
        table[x0 + p_n_minus_one][y0 + p_n_minus_one - 1] = e;
        table[x0 + p_n_minus_one - 1][y0 + p_n_minus_one] = e;
        e++;
        solve(table, n - 1, x0, y0, p_n_minus_one - 1, p_n_minus_one - 1);
        solve(table, n - 1, x0 + p_n_minus_one, y0, 0, p_n_minus_one - 1);
        solve(table, n - 1, x0, y0 + p_n_minus_one, p_n_minus_one - 1, 0);
        solve(table, n - 1, x0 + p_n_minus_one, y0 + p_n_minus_one, x - x0, y - y0);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> k;
    cin >> x >> y;
    x--;
    y--;
    vector<vector<int>> table(pow(2, k), vector<int> (pow(2, k)));
    

    // algorithm
    ///////////////////////////////////////
    // 입력이 x, y 순서로 들어오기에, y, x -> r, c를 넣기
    solve(table, k, 0, 0, y, x);
    table[y][x] = -1;

    // output
    ///////////////////////////////////////
    for (int i = sz(table) - 1; i >= 0; i--)
    {
        for (uint j = 0; j < sz(table[0]); j++)
        {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/