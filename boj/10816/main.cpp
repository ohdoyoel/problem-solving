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
uint n, m;
unordered_map<string, int> table;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (table.find(s) == table.end())
        {
            table[s] = 1;
        }
        else
        {
            table[s]++;
        }
    }
    cin >> m;
    for (uint i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        cout << table[s] << ' ';
    }
    cout << endl;

    // algorithm
    ///////////////////////////////////////

    // output
    ///////////////////////////////////////
    

    return 0;
}