#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<bool> P;

bool makeable(int x) {
    string xStr = to_string(x);
    for (int i=0; i<xStr.size(); ++i) if (!P[xStr[i]-'0']) return false;
    return true;
}

int solve() {
    int ret = 987654321;
    //바로 +-
    ret = min(ret, abs(n-100));
    // 숫자 입력 후 +-
    for (int i=0; i<1000001; ++i) {
        if (makeable(i)) ret = min(ret, static_cast<int>(abs(n-i)+to_string(i).size()));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; P.resize(10);
    for (int i=0; i<10; ++i) P[i] = true;
    int m; cin >> m;
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        P[x] = false;
    }
    cout << solve() << endl;
}