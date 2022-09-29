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

int comb (int i, int j)
{
    if (i == j || j == 0) return 1;
    return comb(i - 1, j) + comb(i - 1, j - 1);
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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count++;
        
    }

    // output
    ///////////////////////////////////////
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/