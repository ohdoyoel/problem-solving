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
int ind;
vector<int> v;
int answer[2] = {0, 0};
int real_answer[2] = {0, 0};
lld _min = 9999999999;
lld _m = 9999999999;

void binarySearch(int ind, int l, int r)
{
    if (l > r) return;
    int m = (l + r) / 2;
    if (ind == m)
    {
        binarySearch(ind, l, m - 1);
        binarySearch(ind, m + 1, r);
        return;
    }
    int sum = v[ind] + v[m];
    if (abs(sum) < _min)
    {
        _min = abs(sum);
        answer[0] = v[ind];
        answer[1] = v[m];
    }
    if (sum < 0)
    {
        return binarySearch(ind, m + 1, r);
    }
    else if (sum == 0)
    {
        return;
    }
    else return binarySearch(ind, l, m - 1);
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
        v.push_back(x);
    }
    sort(all(v));

    for (int i = 0; i < n; i++)
    {
        ind = i;
        binarySearch(ind, ind + 1, sz(v) - 1);
        int s = answer[0] + answer[1];
        if (abs(s) < _m)
        {
            _m = abs(s);
            real_answer[0] = answer[0];
            real_answer[1] = answer[1];
        }
    }

    cout << real_answer[0] << " " << real_answer[1] << endl;
    
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