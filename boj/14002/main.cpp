#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int n;
int cache[1002];
vector<int> A;
vector<int> result = {};

void print() {
    for (int i = 0; i < n; ++i) cout << result[i] << " ";
    cout << endl;
}

// from ~ 끝까지 증가하는 부분 수열의 길이
int solve(int from) {
    int& ret = cache[from+1];
    if (ret != -1) return ret;

    if (from != -1) result.push_back(A[from]);
    if (from == n - 1) return ret = 1;

    ret = 1;
    for (int next = from+1; next < n; ++next) {
        if (from == -1 || A[next] > A[from]) {
            int cand = 1 + solve(next);
            if (cand > ret) ret = cand;
            else if (cand < ret) result.pop_back();
        }
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n; A.resize(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << solve(-1) - 1 << endl;
    print();
}