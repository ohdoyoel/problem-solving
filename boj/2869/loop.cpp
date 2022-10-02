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
int a, b, v;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> a >> b >> v;

    // algorithm
    ///////////////////////////////////////
    int res = 0;
    int dis = 0;
    while (true)
    {
        res++;
        dis += a;
        if (dis >= v) break;
        dis -= b;
    }

    // output
    ///////////////////////////////////////
    cout << res << endl;;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/