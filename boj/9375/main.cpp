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
uint t;
unordered_map<string, int> um;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> t;
    for (uint i = 0; i < t; i++)
    {
        uint n;
        cin >> n;
        um.clear();

        for (uint j = 0; j < n; j++)
        {
            string a, b;
            cin >> a >> b;
            um[b]++;
        }
        
        uint total_len = 1;
        for (auto i = um.begin(); i != um.end(); i++)
        {
            total_len *= (i->second + 1);
        }

        cout << total_len - 1 << endl;
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

*/