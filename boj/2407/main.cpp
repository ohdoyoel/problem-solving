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
int n, m;

lld fact(int n)
{
    if (n == 1) return 1;
    return n * fact(n - 1);
}

lld comb(int i, int j)
{
    return fact(i) / (fact(j) * fact(i - j));
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;

    // algorithm
    ///////////////////////////////////////

    // output
    ///////////////////////////////////////
    cout << comb (n, m) << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/