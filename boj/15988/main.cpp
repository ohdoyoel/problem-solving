#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1000001];

int ott(int n) {
    if (n==0) return 1;

    int& ret = cache[n];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=1; i<3 && i<=n; i++) ret += ott(n-i);
    return ret;
}

int main() {
    ios_base::sync_with_sttdio(0); cin.tie(0); cout.tie(0);
    
    memset(cache, -1, sizeof(cache));
    int c; cin >> c;
    while(c--) {
        int n; cin >> n;
        cout << ott(n) << endl;
    }
}