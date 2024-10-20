#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

string pwd;
int cache[5001];

// 암호[i~n] -> 해석 가능한 가지수
int decrp(int i) {
    // cout << pwd[i] << endl;
    
    if (i == pwd.size()) return 1;
    if (i > pwd.size()) return 0;
    
    int& ret = cache[i];
    if (ret!=-1) return ret;

    // 1: 1, 1x 두가지로 해석됨
    // 2: 2, 2x 두가지로 해석됨
    // 3~9: 한가지로 해석됨
    ret = 0;
    for (int i=0; i<pwd.size(); i++) {
        ret += decrp(i+1);
        int n = pwd[i] - '0';
        if (n==1 || n==2) ret += decrp(i+2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> pwd;
    for (int i=0; i<pwd.size(); i++) {
        if (pwd[i]=='0') {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << decrp(0) << endl;

    return 0;
}