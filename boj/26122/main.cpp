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
int k;
string str;
int res;

int score(int i)
{
    int s = 0;
    while(true)
    {
        if (i - s < 0 || i + 1 + s >= k) break;
        if ((str[i - s] == str[i]) && (str[i + 1] == str[i + 1 + s])) s++;
        else break;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> k;
    cin >> str;

    // algorithm
    ///////////////////////////////////////

    int res = 0;

    for (int i = 0; i < k - 1; i++)
    {
        if (str[i] != str[i + 1])
        {
            int sc = score(i);
            if (res < sc) res = sc;
        }
    }

    // output
    ///////////////////////////////////////
    cout << 2 * res << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/