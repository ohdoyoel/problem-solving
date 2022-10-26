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
int n, m;
vector<int> result;

void solve(int prev, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
        return ;
    }
    
    int temp;
    for (int i = prev; i <= n; i++)
    {
        result.push_back(i);
        prev = i;
        solve(prev, cnt + 1);
        result.pop_back();
        prev = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> m;

    // algorithm
    ///////////////////////////////////////
    solve(1, 0);

    // output
    ///////////////////////////////////////

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/