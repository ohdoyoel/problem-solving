#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
#define inf 987654321
using namespace std;

int cache[101][101][11];
vector<int> seq;

// start부터 end까지의 수열 중 정수로 대응된 LSS
int lss(int start, int end) {
    if (seq[start] == seq[end - 1]) return 0;
    
    int ret = inf;
    for (int v = seq[start]; v <= seq[end - 1]; ++v) {
        int sse = 0;
        for (int i = start; i < end; i++) sse += pow(seq[i] - v, 2);
        ret = min(ret, sse);
    }
    return ret;
}

// seq를 s개로 양자화했을 때 나오는 LSS
int solve(int start, int end, int s) {
    int& ret = cache[start][end][s];
    if (ret != -1) return ret;

    if (s == 0) return ret = 0;

    ret = inf;
    for (int l = start + 1; l <= end; ++l)
        ret = min(ret, lss(start, l) + solve(l, end, s - 1));
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        int n, s;
        cin >> n >> s;
        seq.resize(n);
        for (int i = 0; i < n; ++i) cin >> seq[i];
        sort(seq.begin(), seq.end());
        cout << solve(0, 3, s) << endl;
        // cout << solve(0, sz(seq), s) << endl;
    }
}