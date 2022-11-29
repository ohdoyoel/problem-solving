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
long double a, b, c;
#define EPS 1e-9

long double func(long double x)
{
    return a * x + b * sin(x);
}

long double binarySearch(long double l, long double r)
{
    long double x = (l + r) / 2;
    if (func(x) < (c - EPS)) return binarySearch(x, r);
    else if ((c - EPS) < func(x) && func(x) < (c + EPS)) return x;
    else return binarySearch(l, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    // tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> a >> b >> c;
    // algorithm
    ///////////////////////////////////////
    // cout << ((c - b) / a) << endl;
    // cout << ((c - b) / a) << endl;
    // long double y = 21;
    // cout << sin(y) << endl;
    cout.precision(20);
    cout << binarySearch(((c - b) / a), ((c + b) / a)) << endl;

    // output
    ///////////////////////////////////////
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/