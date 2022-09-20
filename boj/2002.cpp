#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint n;
unordered_map<string, int> in;
uint ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n;
    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        in[s] = i;
    }
    for (uint i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (in[s] > i)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}