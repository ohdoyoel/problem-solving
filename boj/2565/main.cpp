#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int n;
int cache[501];
vector<int> connectedTo(501, 0);

// a를 유지하되, a~끝까지의 전봇대에서 교차하지 않는 전깃줄의 최대 개수
int solve(int a) {
    int& ret = cache[a];
    if (ret != -1) return ret;

    if (a == 500) return ret = 0;
    if (connectedTo[a] == 0) return solve(a+1);
    
    ret = 1;
    for (int next = a+1; next < 501; next++) if (connectedTo[next] > connectedTo[a]) ret = max(ret, 1 + solve(next));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    int c = n;
    while(c--) {
        int a, b; cin >> a >> b;
        connectedTo[a] = b;
    }
    int m = 0;
    for (int i = 1; i < 501; ++i) m = max(m, solve(i));
    cout << n-m << endl;
    // cout << solve(1) << endl;
    // cout << solve(2) << endl;
    // cout << solve(3) << endl;
    // cout << solve(4) << endl;
    // cout << solve(5) << endl;
    // cout << solve(6) << endl;
    // cout << solve(7) << endl;
    // cout << solve(8) << endl;
    // cout << solve(9) << endl;
    // cout << solve(10) << endl;
}