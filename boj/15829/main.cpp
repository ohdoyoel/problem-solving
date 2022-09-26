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
uint n;
string input;
unsigned long long ans = 0;

uint modular(uint i)
{
    if (i == 0) return 1;
    return (31 * modular(i - 1) % 1234567891) % 1234567891;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    cin >> input;

    // algorithm
    ///////////////////////////////////////
    for (uint i = 0; i < n; i++)
    {
        ans += int(((input[i] - 'a' + 1) * (modular(i)))) % 1234567891;
    }
    
    // output
    ///////////////////////////////////////
    cout << ans % 1234567891 << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/