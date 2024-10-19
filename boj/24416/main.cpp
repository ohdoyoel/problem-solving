#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int fibCnt = 0;
int fib(int n) {
    fibCnt++;
    if (n<=2) return 1;
    return fib(n-1)+fib(n-2);
}

int fibonacciCache[41];
int fibonacciCnt = 0;
int fibonacci(int n) {
    fibonacciCache[1] = fibonacciCache[2] = 1;
    for (int i=3; i<=n; i++) {
        fibonacciCnt++;
        fibonacciCache[i] = fibonacciCache[i-1] + fibonacciCache[i-2];
    }
    return fibonacciCache[n];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    fib(n); fibonacciCache(n);
    cout << fibCnt << " " << fibonacciCnt << endl;
    return 0;
}