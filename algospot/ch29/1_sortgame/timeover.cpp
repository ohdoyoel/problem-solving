#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
map<vector<int>, int> dist;

int precalc(){
    vector<int> V;
    for (int i=0; i<n; ++i) V.push_back(i);

    queue<vector<int>> Q;

    dist[V] = 0;
    Q.push(V);

    while(!Q.empty()) {
        vector<int> here = Q.front(); Q.pop();
        int cost = dist[here];

        for (int i=0; i<n; ++i) {
            for (int j=i+2; j<=n; ++j) {
                reverse(here.begin()+i, here.begin()+j);
                if (dist.count(here) == 0) {
                    dist[here] = cost + 1;
                    Q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        vector<int> A;
        cin >> n; A.resize(n);
        precalc();
        for (int i=0; i<n; ++i) cin >> A[i];
        vector<int> B; B.resize(n);
        for (int i=0; i<n; ++i) {
            int smaller = 0;
            for (int j=0; j<n; ++j) if (A[j] < A[i]) smaller++;
            B[i] = smaller;
        }
        cout << dist[B] << endl;
    }
}