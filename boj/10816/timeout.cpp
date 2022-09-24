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

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    vector<int> v_input(n);
    for (uint i = 0; i < n; i++)
    {
        cin >> v_input[i];
    }
    cin >> m;
    vector<int> v_output(m);
    for (uint i = 0; i < m; i++)
    {
        cin >> v_output[i];
    }

    // algorithm
    ///////////////////////////////////////
    for (uint i = 0; i < m; i++)
    {
        int x = v_output[i];
        int ans = 0;
        for (uint j = 0; j < n; j++)
        {
            if (v_input[j] == x)
            {
                ans++;
            }
        }
        cout << ans << ' ';
    }
    cout << endl;

    // output
    ///////////////////////////////////////
    

    return 0;
}