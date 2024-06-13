#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int calledCnt;

int recursion(const char *s, int l, int r){
    calledCnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main() {
    int t; cin >> t;
    
    while(t--) {
        string s; cin >> s;

        calledCnt = 0;
        cout << isPalindrome(&(s[0])) << " " << calledCnt << endl;
    }
}