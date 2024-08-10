#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int ret, n;
vector<vector<bool>> areFriends;
vector<bool> taken;

void solve() {
    int firstFree = -1;
    for (int i=0; i<n; i++) if (!taken[i]) {
        firstFree = i;
        break;
    }
    if (firstFree == -1) {
        ret++;
        return;
    }

    for (int cand=firstFree+1; cand<n; cand++) {
        if (!taken[cand] && areFriends[firstFree][cand]) {
            taken[firstFree] = taken[cand] = true;
            solve();
            taken[firstFree] = taken[cand] = false;
        }
    }
}

int main() {
    int c; cin >> c;
    while(c--) {
        int m; cin >> n >> m;
        taken.resize(n);
        areFriends.resize(n);
        for (int i=0; i<n; i++) {
            taken[i] = false;
            areFriends[i].resize(n);
            for (int j=0; j<n; j++) areFriends[i][j] = false;
        }

        while (m--) {
            int a, b; cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }

        ret = 0;
        solve();
        cout << ret << endl;
    }
}