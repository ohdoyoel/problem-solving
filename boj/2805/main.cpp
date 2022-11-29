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
int h;

void binarySearch(int min, int max)
{
    if (min > max) return;
    int mid = (min + max) / 2;
    lld s = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > mid)
        {
            s += (v[i] - mid);
        }
    }
    if (s > m)
    {
        h = mid;
        binarySearch(mid + 1, max);
    }
    else if (s == m)
    {
        h = mid;
        return;
    }
    else
    {
        binarySearch(min, mid - 1);
    }
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
    binarySearch(0, *max_element(v.begin(), v.end()));

    // output
    ///////////////////////////////////////
    cout << h << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/