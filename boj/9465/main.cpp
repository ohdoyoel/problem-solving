#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;
using pii = pair<int, int>;

int cache[2][100001];
vector<int[2]> score;

// n번째 f번째 층의 스티커를 찢고 (0 또는 1), n번째 ~ 끝까지 봤을 때 점수 최댓값
int solve(int f, int n) {
    int& ret = cache[f][n];
    if (ret != -1) return ret;

    // if (n == sz(score) - 1) return ret = score[n][f];

    ret = 0;
    for (int i = n; i < sz(score); ++i)
        for (int j = 0; j < 2; ++j)
            ret = max(ret, solve(j, i));
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        int n;
        cin >> n;
        score.resize(n);
        for (int i = 0; i < n; ++i) cin >> score[i][0] >> score[i][1];

    }
}