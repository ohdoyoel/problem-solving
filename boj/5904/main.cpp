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
uint n, k;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;

    // algorithm
    ///////////////////////////////////////
    uint i = 0;
    k = 3;
    while (true)
    {
        if (n <= k) break;
        k = 3 * k + 1;
        i++;
    }
    cout << i;

    // solve(k);/

    // output
    ///////////////////////////////////////

    return 0;
}