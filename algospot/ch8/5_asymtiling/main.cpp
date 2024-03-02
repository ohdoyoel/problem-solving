#include<bits/stdc++.h>
#define sz(x) (uint)(x).size()
#define endl "\n"
using namespace std;

int cache[101];

int solve(int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    if (n == 1) return 0;
    else if (n == 2) return 0;
    else if (n == 3) return 2;
    

    if (n % 2) return ret= solve(n - 1) + solve(n - 2) - solve(n / 2) - solve(n / 2 - 1);
    return ret = solve(n - 1) + solve(n - 2) - solve(n / 2);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}