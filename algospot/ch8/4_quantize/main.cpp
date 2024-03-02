#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
#define inf 987654321
using namespace std;

int cache[101][11];
vector<int> seq;

// start부터 end까지의 수열 중 정수로 대응된 LSS
int lss(int start, int end) {
    if (seq[start] == seq[end - 1]) return 0;
    
    double avrg = 0;
    for (int i = start; i < end; ++i) avrg += seq[i];
    avrg /= (end - start);

    int sse = 0;
    for (int i = start; i < end; i++) sse += pow(seq[i] - round(avrg), 2);
    
    return sse;
}

// seq를 s개로 양자화했을 때 나오는 LSS
int solve(int start, int s) {
    if (start == sz(seq)) return 0;
    if (s == 0) return inf;
  
    int& ret = cache[start][s];
    if (ret != -1) return ret;

    ret = inf;
    for (int l = start + 1; l <= sz(seq); ++l)
        ret = min(ret, lss(start, l) + solve(l, s - 1));
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
        cout << solve(0, s) << endl;
    }
}