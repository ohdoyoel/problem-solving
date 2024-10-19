#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][11];
vector<int> A;
int n;

// sum of square error, 값하나로
int sse(int i, int j) {
    double m = 0;
    for (int k=i; k<j; k++) m += A[k];
    m /= (j-i);

    int sum = 0;
    for (int l=i; l<j; l++) sum += pow((A[l] - round(m)), 2);
    return sum;
}

// A[i...]을 s로 양자화한 했을 때 least sum of square error
int lsse(int i, int s) {
    if (i==n) return 0;
    if (s==0) return 987654321;

    int& ret = cache[i][s];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int j=i+1; j<=n; j++) {
      ret = min(ret, sse(i, j)+lsse(j, s-1));
      // cout << ret << endl;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c; cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        int s; cin >> n >> s; A.resize(n);
        for (int i=0; i<n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        cout << lsse(0, s) << endl;
    }

    return 0;
}