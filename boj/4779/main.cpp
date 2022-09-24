#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n;
string str;

void solve(uint s, uint n)
{
    if (n == 0)
    {
        return ;
    }
    for (uint i = s + pow(3, n - 1); i < s + 2 * pow(3, n - 1); i++)
    {
        str[i] = ' ';
    }
    solve(s, n - 1);
    solve(s + 2 * pow(3, n - 1), n - 1);
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    while (true)
    {
        cin >> n;
        
        if (cin.eof()) break;
        
        str = "";
        for (uint i = 0; i < pow(3, n); i++) str += '-';
        
        solve(0, n);
        
        cout << str << endl;
    }

    return 0;
}