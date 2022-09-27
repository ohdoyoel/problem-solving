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
string a, b;
vector<string> ans_vec;

bool cmp(string a, string b)
{
    return a.size() > b.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> a >> b;

    // algorithm
    ///////////////////////////////////////
    uint p;
    string ans;
    for (uint k = 0; k < a.length(); k++)
    {
        p = 0;
        ans = "";
        for (uint i = k; i < a.length(); i++)
        {
            for (uint j = p; j < b.length(); j++)
            {
                if (a[i] == b[j])
                {
                    ans += a[i];
                    p = j + 1;
                    break;
                }
            }
        }
        ans_vec.push_back(ans);
    }

    sort(all(ans_vec), cmp);

    // output
    ///////////////////////////////////////
    for (uint i = 0; i < ans_vec.size(); i++)
    {
        cout << ans_vec[i] << endl;
    }

    cout << ans_vec[0] << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/

//반례
/*
ATBD
ABDT
*/