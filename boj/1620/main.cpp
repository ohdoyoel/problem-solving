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
unordered_map<string, int> _stoi;
unordered_map<int, string> itos;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;

    // algorithm
    ///////////////////////////////////////
    for (uint i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        _stoi[s] = i;
        itos[i] = s;
    }

    // output
    ///////////////////////////////////////
    for (uint i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (isdigit(s[0]))
        {
            cout << itos[atoi(&s[0])] << endl;
        }
        else
        {
            cout << _stoi[s] << endl;
        }
    }
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/