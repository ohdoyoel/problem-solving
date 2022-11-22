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

vector<int> partition1(vector<int> v, int n)
{
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(v[i]);
    }
    return a;
}

vector<int> partition2(vector<int> v, int n)
{
    vector<int> a;
    for (int i = n; i < sz(v); i++)
    {
        a.push_back(v[i]);
    }
    return a;
}

vector<int> merge(vector<int> a, vector<int> b)
{
    for (int i = 0; i < sz(b); i++)
    {
        a.push_back(b[i]);
    }
    return a;
}

void mergeSort(vector<int> v)
{
    vector<int> a, b;
    a = partition1(v, sz(v) / 2);
    b = partition2(v, sz(v) / 2);
    mergeSort(a);
    mergeSort(b);
    A = merge(a, b);
}

bool binarySearch(int k, int l, int r)
{
    if (l == r) return false;
    int i = (l + r) / 2;
    if (k < A[i]) return binarySearch(k, l, i - 1);
    if (k == A[i]) return true;
    if (k > A[i]) return binarySearch(k, i + 1, r);
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
        cout << binarySearch(x, 0, n) << endl;
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