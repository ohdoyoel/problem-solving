#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> A;
vector<int> B;
vector<int> result;

int cache[100][100];

// i, j번째 이후를 관찰하여 나오는 jlis의 길이
int jlis(int i, int j) {
    int& ret = cache[i][j];
    if (ret != 0) return ret;
    
    // if (i == sz(A) - 1 && j == sz(B) - 1) return ret = (A[i] == B[j]) ? 1 : 2;

    ret = 1;
    int k = max(A[i], B[j]);
    for (int is = i + 1; is < sz(A); ++is) {
        if (A[is] > k) ret = max(ret, 1 + jlis(is, j));
    }
    for (int js = j + 1; js < sz(B); ++js) {
        if (B[js] > k) ret = max(ret, 1 + jlis(i, js));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c;

    while (c--) {
        memset(cache, 0, sizeof(cache));

        int n, m;
        cin >> n >> m;
        A.resize(n);
        B.resize(m);

        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int j = 0; j < m; ++j) cin >> B[j];

        cout << jlis(0, 0) << endl;
    }

    return 0;
}