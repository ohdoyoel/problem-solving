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
uint t;
uint n, m;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> t;
    for (uint i = 0; i < t; i++)
    {
        cin >> n >> m;
        queue<pair<int, int>> q;
        vector<uint> v(n);
        for (uint j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[j] = x;
            if (j == m) q.push(make_pair(x, 1));
            else q. push(make_pair(x, 0));
        }

        sort(all(v));
        int ans = 1;
        while (true)
        {
            if (q.front().first == v.back() && q.front().second == 1)
            {
                break;
            }
            else if (q.front().first == v.back() && q.front().second == 0)
            {
                q.pop();
                v.pop_back();
                ans++;
            }
            else
            {
                pair<int, int> x = q.front();
                q.pop();
                q.push(x);
            }
        }
        cout << ans << endl;
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
sort(importance)
ans = 0;
if (q.front == v.back && 찾던 놈) print(ans); break;
if (q.front == v.back && 찾던 놈x) q.pop; v.pop_back; ans++;
if (q.front != v.back) q.pop and push; 
*/