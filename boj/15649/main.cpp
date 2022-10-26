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
bool visited[9];
vector<int> result;

// if cnt = m, print result
// if not, just build result: if visited, jump, if not visited, update visited true, and call solve, and update visited false
void solve(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        visited[i] = 1;
        result.push_back(i);
        solve(cnt + 1);
        visited[i] = 0;
        result.pop_back();
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
    solve(0);

    // output
    ///////////////////////////////////////

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/