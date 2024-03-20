#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int,int>;

struct node {
    vector<node*> children;
};

int radius () {
    int ret = 0;
    for (int i=0; i<n; i++) {

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n; adjacent.resize(n+1); visited.resize(n+1);
    int t = n-1;
    while(t--) {
        int i, d, c; cin >> i >> d >> c;
        adjacent[i].push_back(make_pair(d, c));
    }
    cout << radius() << endl;
}