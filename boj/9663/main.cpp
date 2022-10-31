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
vector<int> col;

bool promising(int i)
{
    for (int j = 0; j < i; j++)
    {
        if (col[j] == col[i] || abs(col[i] - col[j]) == abs(i - j)) return false;
    }
    return true;
}

void solve(int cnt)
{
    if (cnt == n)
    {
        res++;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        col[cnt] = j;
        if (promising(cnt)) solve(cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    col = vector<int>(n, 0);

    // algorithm
    ///////////////////////////////////////
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