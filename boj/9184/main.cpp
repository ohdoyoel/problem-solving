#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[101][101][101];

int w(int a, int b, int c) {
    int& ret = cache[a+50][b+50][c+50];
    if (ret != -1) return ret;

    if (a <= 0 || b <= 0 || c <= 0) return ret = 1;
    else if (a > 20 || b > 20 || c > 20) return ret = w(20, 20, 20);
    else if (a < b && b < c) return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
    memset(cache, -1, sizeof(cache));
    while(1) {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
}