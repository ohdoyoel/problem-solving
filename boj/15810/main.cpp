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
lld m;
vector<int> v;
int t;

void binarySearch(int l, int r)
{
    if (l > r) return;
    int mid = (l + r) / 2;
    lld s = 0;
    for (int i = 0; i < sz(v); i++)
    {
        s += (mid / v[i]);
    }
    if (s > m)
    {
        t = mid;
        binarySearch(l, mid - 1);
    }
    else if (s == m)
    {
        t = mid;
        binarySearch(l, mid - 1);
    }
    else binarySearch(mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // algorithm
    ///////////////////////////////////////
    binarySearch(0, (*min_element(v.begin(), v.end())) * m);

    // output
    ///////////////////////////////////////
    cout << t << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/