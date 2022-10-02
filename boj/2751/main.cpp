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
int n;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // algorithm
    ///////////////////////////////////////
    sort(all(v));

    // output
    ///////////////////////////////////////
    for (int i = 0; i < sz(v); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/