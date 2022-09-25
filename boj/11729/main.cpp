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
uint n;

uint inst_len(uint k)
{
    if (k == 1) return 1;
    return 2 * inst_len(k - 1) + 1;
}

uint other(uint x, uint y)
{
    return 6 - x - y;
}

void solve(uint k, uint current, uint target)
{
    if (k == 1)
    {
        cout << current << ' ' << target << endl;
        return;
    }
    solve(k - 1, current, other(current, target));
    solve(1, current, target);
    solve(k - 1, other(current, target), target);
    return;
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
    if (n <= 20)
    {
        cout << inst_len(n) << endl;
        solve(n, 1, 3);
    }
    else
    {
        cout << inst_len(n) << endl;
    }
    
    // output
    ///////////////////////////////////////

    return 0;
}

// pseudo code
///////////////////////////////////////
/*
uint n <- input
table <- [vector<int>a(0~n), vector<int>b, vector<int>c]

void solve(n, current, target)
    if (n == 1)
        table[current].back to table[target].push_back
        print(current, target)
        return ;
    solve(n - 1, current, space)
    print(1, current, target)
    return ;

solve(n, 1, 3)
*/