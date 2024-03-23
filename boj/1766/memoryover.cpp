#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

list<int> l;

int main() {
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) l.push_back(i);
    
    while(m--) {
        int a, b; cin >> a >> b;

        auto aIt = l.begin();
        while(*aIt != a) aIt++;
        l.erase(aIt);

        auto bIt = l.begin();
        while(*bIt != b) bIt++;
        for (auto it=l.begin(); it!=next(bIt,1); it++) {
            if (*it > a || it==bIt) l.insert(it, a);
        }
    }
    
    for (int e : l) cout << e << " ";
    cout << endl;
}