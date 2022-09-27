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
unordered_map<string, string> um;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;

    // algorithm
    ///////////////////////////////////////
    for (uint i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        um[a] = b;
    }

    // output
    ///////////////////////////////////////
    for (uint j = 0; j < m; j++)
    {
        string s;
        cin >> s;
        cout << um[s] << endl;
    }
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/