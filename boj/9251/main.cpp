#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1000][1000];
string A, B;

// a, b 인덱스부터 끝까지 자른 부분 문자열의 lcs
int lcs(int a, int b) {
    if (a == sz(A) || b == sz(B)) return 0;

    int& ret = cache[a][b];
    if (ret != -1) return ret;

    if (a == sz(A) - 1 && b == sz(B) - 1) return ret = (A[a] == B[b]);

    ret = 0;
    for (int i = a; i < sz(A); ++i)
        for (int j = b; j < sz(B); ++j)
            if (A[i] == B[j]) ret = max(ret, 1 + lcs(i + 1, j + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(cache, -1, sizeof(cache));
    cin >> A >> B;
    cout << lcs(0, 0) << endl;
}