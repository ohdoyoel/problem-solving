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
vector<int> A;
int m;

bool binarySearch(int k, int l, int r)
{
    if (l > r) return false;
    int i = (l + r) / 2;
    if (k < A[i]) return binarySearch(k, l, i - 1);
    else if (k == A[i]) return true;
    else return binarySearch(k, i + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
        
    }
    sort(all(A));
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        int x;
        cin >> x;
        cout << binarySearch(x, 0, n - 1) << endl;
    }


    // algorithm
    ///////////////////////////////////////
    

    // output
    ///////////////////////////////////////
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/