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

void check_candidate(int i, int j) // build eixst_num
{
    for (int k = 0; k < 10; k++) exist_num[k]++;
    int pv_x = (i / 3) * 3, pv_y = (j / 3) * 3;

    for (int k = 0; k < 9; k++)
    {
        exist_num[table[k][y]] = true;
        exist_num[table[x][k]] = true;
    }

    for (int ic = 0; ic < 3; ic++)
    {
        for (int jc = 0; jc < 3; jc++)
        {
            exist_num[table[i + ic][j + jc]] = true;
        }
    }
}

void check_again(int i, int j, int num)
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
            if (table[i + ic][j + jc] == num) return false;
        }
    }
}

void solve(int i)
{
    if (zeros == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
            cout << endl;
        }
    }

    int i = n / 9, j = n % 9;

    if (table[i][j] == 0)
    {
        check_candidate(i, j)
        for (int k = 1; k <= 9; k++)
        {
            if (exist_num[k] == false && check_again(i, j, k))
            {
                table[i][j] = k;
                exist_num[k] = true;
                zeros
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 0; j++)
        {
            cin >> talbe[i][j];
            if (table[i][j] == 0) zeros++;
        }
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
2차원 배열에서 각 원소를 숫자로 매핑하면 행 = n / 9, 열 = n % 9로 표현할 수 있다.
*/