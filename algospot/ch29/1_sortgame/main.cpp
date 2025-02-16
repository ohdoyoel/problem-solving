#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
map<vector<int>, int> distance;

int precalc(){
    vector<int> V;
    for (int i=0; i<n; ++i) V.push_back(i);

    queue<vector<int>> Q;

    distance[V] = 0;
    Q.push(V);

    while(!Q.empty()) {
        vector<int> here = Q.front(); Q.pop();
        int cost = distance[here];

        for (int i=0; i<n; ++i) {
            for (int j=2; j<=n; ++j) {
                reverse(here.begin()+i, here.begin()+j);
                if (distance.count(here) == 0) {
                    distance[here] = cost + 1;
                    Q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precalc();
    int c; cin >> c;
    while (c--) {
        vector<int> A;
        cin >> n; A.resize(n);
        for (int i=0; i<n; ++i) cin >> A[i];
        vecotor<int> B; B.resize(n);
        for (int i=0; i<A.size(); ++i) {
            int smaller = 0;
            for (int j=0; j<A.size(); ++j) if (A[j] < A[i]) smaller++;
            B[i] = smaller;
        }
        cout << distance[B] << endl;
    }
}