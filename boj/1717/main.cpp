#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int elemToSet[1000001];

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<=n; i++) elemToSet[i] = i;

    while(m--) {
        int c, a, b; cin >> c >> a >> b;
        switch (c) {
            case 0:
            {
                if (a == b) break;
                int s = min(elemToSet[a], elemToSet[b]);
                elemToSet[a] = s; elemToSet[b] = s;
                break;
            }
            case 1:
            {
                if(a == b || elemToSet[a] == elemToSet[b]) cout << "YES" << endl;
                else cout << "NO" << endl;
                break;
            }
        }
    }
}