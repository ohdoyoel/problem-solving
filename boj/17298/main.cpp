#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

map<int, int> A;

int nge(map<int,int>::iterator it) {
    auto jt =it;
    while(jt != A.end()) {
        if (jt->second > it->second) return jt->first;
        jt++;
    }
    return -1;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        A[a] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (auto pii = A.begin(); pii != A.end(); pii++) if (i == pii->second) cout << nge(pii) << " ";
    }
    cout << endl;
}