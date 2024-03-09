#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[2001][2001];
int n;
vector<int> seq;

// s~e까지 팰린드롬인지 반환
bool isPldrm(int start, int end) {
    int &ret = cache[start][end];
    if (ret != -1) return ret;

    if (start >= end) return ret = true;

    return ret = (seq[start] == seq[end]) && isPldrm(start+1, end-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n; seq.resize(n);
    for (int i = 0; i < n; ++i) cin >> seq[i];
    int m; cin >> m;
    while(m--) {
        int s, e; cin >> s >> e;
        cout << isPldrm(s-1, e-1) << endl;
    }
}