#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1001];

// 상근이 차례에 n개가 남았을 때 상근이가 이기나?
int isSKwin(int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;

    if (n == 1 || n == 3) return ret = 1;
    else if (n == 0 || n == 2) return ret = 0;

    return ret = isSKwin(n - 2);
}

int main() {
    int n; cin >> n;
    if (isSKwin(n)) cout << "SK" << endl;
    else cout << "CY" << endl;
}