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
string n;
uint ans = 0;

int sum_and_mod(string i)
{
    if (i.length() == 1) return (i[0] - '0') % 3;
    ans++;
    int sum = 0;
    for (uint j = 0; j < i.size(); j++)
    {
        sum += (i[j] - '0');
    }
    return sum_and_mod(to_string(sum)) % 3;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;

    // algorithm
    ///////////////////////////////////////
    int x = sum_and_mod(n);


    // output
    ///////////////////////////////////////
    cout << ans << endl;
    if (x != 0) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/