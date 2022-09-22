#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n;
uint ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    unordered_map<string, int> in_um;
    unordered_map<string, int> out_um;
    vector<string> in;
    vector<string> out;

    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        in_um[s] = i;
        in.push_back(s);
    }

    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        out_um[s] = i;
        out.push_back(s);
    }

    for (uint i = 0; i < sz(in); i++)
    {
        bool flag = false;
        
        for (uint j = 0; j < in_um[out[i]]; j++)
        {
            if (out_um[in[j]] > out_um[out[i]])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}