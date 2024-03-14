#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

set<string> strSet;

int main() {
    int n, m; cin >> n >> m;
    while(n--) {
        string s; cin >> s;
        strSet.insert(s);
    }

    int ret = 0;
    while(m--) {
        string s; cin >> s;
        if (strSet.contains(s)) ret++;
    }
    cout << ret << endl;
}