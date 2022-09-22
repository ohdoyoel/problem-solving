#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n, m;
unordered_map<string, bool> um;
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        um[s] = true;
    }
    for (uint i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (um[s]) ans.push_back(s);
    }
    sort(all(ans));

    cout << sz(ans) << endl;
    for (uint i = 0; i < sz(ans); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}