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
vector<int> v;
int answer[2] = {0, 0};


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
    int l = 0;
    int r = n - 1;
    int cand = 2000000000;
    while (l < r)
    {
        int sum = v[l] + v[r];
        if (cand > abs(sum))
        {
            cand = abs(sum);
            answer[0] = v[l];
            answer[1] = v[r];
            if (sum == 0) break;
        }


        
        if (sum < 0) l++;
        else r--;
    }

    cout << answer[0] << " " << answer[1] << endl;
    
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