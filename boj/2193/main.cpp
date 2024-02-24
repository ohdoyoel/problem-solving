#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[2][91];

// s로 시작하고, 길이가 n인 이친수의 개수
int prinary(int s, int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;

    if (n == 1) return s;
    if (s == 1) return ret = prinary(0, n - 1);
    return ret = prinary(0, n - 1) + prinary(1, n - 1);
}

int main() {
    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;
    cout << prinary(0, n) << endl;

    return 0;
}