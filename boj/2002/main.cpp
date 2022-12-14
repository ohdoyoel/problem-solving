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
    vector<int> out;

    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        in_um[s] = i;
    }

    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        out.push_back(in_um[s]);
    }

    for (uint i = 0; i < n; i++)
    {
        for (uint j = i + 1; j < n; j++)
        {
            if (out[i] > out[j])
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}