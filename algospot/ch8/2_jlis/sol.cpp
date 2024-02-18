#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld NEGINF = numeric_limits<lld>::min();

vector<int> A;
vector<int> B;
int cache[101][101];

// i, j번째 이후를 관찰하여 나오는 jlis의 길이
int jlis(int i, int j) {
    int& ret = cache[i + 1][j + 1];
    if (ret != -1) return ret;
    
    ret = 2;
    lld a = (i == -1 ? NEGINF : A[i]);
    lld b = (j == -1 ? NEGINF : B[j]);
    lld larger = max(a, b);
    for (int is = i + 1; is < sz(A); ++is) {
        if (A[is] > larger) ret = max(ret, 1 + jlis(is, j));
    }
    for (int js = j + 1; js < sz(B); ++js) {
        if (B[js] > larger) ret = max(ret, 1 + jlis(i, js));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c;

    while (c--) {
        memset(cache, -1, sizeof(cache));

        int n, m;
        cin >> n >> m;
        A.resize(n);
        B.resize(m);

        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int j = 0; j < m; ++j) cin >> B[j];

        cout << jlis(-1, -1) - 2 << endl;
    }

    return 0;
}

// 모든 경우의 수를 보기 위해 index를 -1에서 시작
// 32 int 가 들어올 수 있기 때문에 NEGINF는 -987654321이 아닌 lld::min()
// 마지막에 -2를 하는 이유는?