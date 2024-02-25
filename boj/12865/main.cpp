#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;
using pii = pair<int, int>;

int cache[101][100001];
vector<pii> weightAndValue;

// n번째부터 끝까지 원소가 있고, 가능한 무게가 k일 때 가치합의 최댓값
int solve(int n, int k) {
    int& ret = cache[n][k];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = n; i < sz(weightAndValue); ++i)
        if (weightAndValue[i].second <= k)
            ret = max(ret, weightAndValue[i].second + solve(i + 1, k - weightAndValue[i].second));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k;
    cin >> n >> k;
    weightAndValue.resize(n);
    for (int i = 0; i < n; ++i) cin >> weightAndValue[i].first >> weightAndValue[i].second;
    cout << solve(0, k) << endl;
}