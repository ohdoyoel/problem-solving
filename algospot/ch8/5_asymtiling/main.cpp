#include<bits/stdc++.h>
#define sz(x) (uint)(x).size()
#define endl "\n"
using namespace std;
using lld = long long int;

lld fib[101];

int main() {    
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < 101; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;

    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        lld res = fib[n];
        if (n % 2) res -= fib[n / 2];
        else res -= ((fib[n / 2 - 1] + fib[n / 2]) % 1000000007);
        if (res < 0) res += 1000000007;
        cout << res << endl;
    }
}