#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> A;
vector<int> B;
int cache[102][102];

// A[i], B[j] 중 1개를 포함한 이후의 jlis
// 따라서 i, j 중 하나가 -1이면 그 배열은 아직 선택X, 둘다 -1이 아니면 큰놈이 선택된 것
int jlis(int i, int j) {
    int& ret = cache[i+1][j+1];
    if (ret != -1) return ret;
    
    int tail = (i==-1 ? B[j] : (j==-1 ? A[i] : max(A[i], B[j])));
    
    ret = 1;
    for (int a=i+1; a<A.size(); a++) if (tail < A[a]) ret = max(ret, 1+jlis(a, j));
    for (int b=j+1; b<B.size(); b++) if (tail < B[b]) ret = max(ret, 1+jlis(i, b));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        int a, b;
        cin >> a >> b; A.resize(a); B.resize(b);
        for (int i=0; i<a; i++) cin >> A[i];
        for (int i=0; i<b; i++) cin >> B[i];
        int res = 0;
        for (int i=0; i<a; i++) res = max(res, jlis(i, -1));
        for (int j=0; j<b; j++) res = max(res, jlis(-1, j));
        cout << res << endl;
    }
    return 0;
}