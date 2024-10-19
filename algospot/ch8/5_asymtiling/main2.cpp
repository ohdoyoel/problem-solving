#include<bits/stdc++.h>
#define endl "\n"
#define MOD 1000000007
using namespace std;

int cache[101];

int all(int n) {
  if (n<=2) return n;
  int& ret = cache[n];
  if (ret!=-1) return ret;
  return ret = (all(n-1) + all(n-2)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c; cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        cout << ((all(n-1) + all(n-2)) % MOD - (n%2 ? all(n/2) : (all(n/2)+all(n/2-1)) % MOD) + MOD) %  MOD << endl;
    }
    
    return 0;
}