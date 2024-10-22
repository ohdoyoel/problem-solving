#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[21][101];
int n;
vector<int> L;
vector<int> J;

int joy(int i, int health) {
    if (health<=0) return -987654321;
    if (i==n) return 0;

    int& ret = cache[i][health];
    if (ret!=-1) return ret;

    ret = 0;
    ret = max(ret, joy(i+1, health));
    ret = max(ret, J[i]+joy(i+1, health-L[i]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n; L.resize(n); J.resize(n);
    for (int i=0; i<n; i++) cin >> L[i];
    for (int i=0; i<n; i++) cin >> J[i];
    cout << joy(0, 100) << endl;
}