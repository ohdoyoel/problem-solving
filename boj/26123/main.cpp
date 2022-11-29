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
int n, d;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> d;

    // algorithm
    ///////////////////////////////////////
    for (int i = 0 ; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    lld res = 0;

    int max = *max_element(v.begin(), v.end());
    int h = max - d;

    if (h < 0) h = 0;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it > h) res += (*it - h);
    }

    // output
    ///////////////////////////////////////
    cout << res << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/