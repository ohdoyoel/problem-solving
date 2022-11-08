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
int zeros = 0;
int table[9][9];
bool exist_num[10];
bool prob;

void check_candidate(int i, int j) // build exist_num
{
    for (int k = 0; k < 10; k++) exist_num[k] = false;
    int pv_x = (i / 3) * 3, pv_y = (j / 3) * 3;

    for (int k = 0; k < 9; k++)
    {
        exist_num[table[k][j]] = true;
        exist_num[table[i][k]] = true;
    }

    for (int ic = 0; ic < 3; ic++)
    {
        for (int jc = 0; jc < 3; jc++)
        {
            exist_num[table[pv_x + ic][pv_y + jc]] = true;
        }
    }

    for (int x = 0; x < 10; x++)
    {
        cout << exist_num[x] << " "; 
    }
    cout << endl;
}

bool check_again(int i, int j, int num)
{
    int pv_x = (i / 3) * 3, pv_y = (j / 3) * 3;
    for (int k = 0; k < 9; k++)
    {
        if (table[i][k] == num) return false;
        if (table[k][j] == num) return false;
    }
    for (int ic = 0; ic < 3; ic++)
    {
        for (int jc = 0; jc < 3; jc++)
        {
            if (table[pv_x + ic][pv_y + jc] == num) return false;
        }
    }
    return true;
}

void solve(int n)
{
    cout << zeros << endl;

    if (zeros == 0 || n == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << table[i][j] << " ";
            cout << endl;
        }
        return ;
    }

    int i = n / 9, j = n % 9;

    if (table[i][j] == 0)
    {
        check_candidate(i, j);
        bool flag = false;
        for (int k = 1; k <= 9; k++)
        {
            if (exist_num[k] == false)
            {
                if (check_again(i, j, k))
                {
                    table[i][j] = k;
                    zeros--;
                    solve(n + 1);
                    if ()
                    {
                        table[i][j] = 0;
                        zeros++;
                    }
                }
                flag = true;
            }
        }
        // 모두 1인 경우 -> 이전에 넣은 놈을 다음 ...
    }
    else
    {
        solve(n + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 0) zeros++;
        }
    }

    // algorithm
    ///////////////////////////////////////
    solve(0);

    // output
    ///////////////////////////////////////

    return 0;
}

// pseudo code
///////////////////////////////////////
/*
2차원 배열에서 각 원소를 숫자로 매핑하면 행 = n / 9, 열 = n % 9로 표현할 수 있다.
*/