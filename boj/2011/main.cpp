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

    ret = 0;

    // 1자리로 먼저 해석
    int first = pwd[i] - '0';
    if (first==0) ret+=0;
    else ret+=1*decrp(i+1);

    if (i==pwd.size()-1) return ret;

    // 2자리로 해석
    int second = pwd[i+1]  - '0';
    if (fisrt==1 && second==0) ret+=1*=decrp(i+2);
    else if (first*10+second<=26) ret+=2*decrp(i+2);
    else ret+=1*=decrp(i+2);

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