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
        ans += (input[i] - 'a' + 1) * (pow(31, i));
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