#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<int>> party;
vector<int> black;

bool isBlack(int i) {
    if (black.find(i) != -1) return true;
    for (int j=0; j<party.size(); j++) {
        if (party[j].find(i) != -1)
    }
}

int main() {
    int n, m; cin >> n >> m; adjacent.resize(m);
    int b; cin >> b;
    for (int i=0; i<b; i++) cin >> black[i];
    for (int i=0; i<m; i++) {
        int p; cin >> p;
        for (int j=0; j<p; j++) {
            for (int k=0; k<p; k++) {
                if (j != k) {
                    int 
                }
            }
        };
    }

    int ret = 0;
    while (m--) {
        int p; cin >> p;
        bool allWhite = true;
        for (int i=0; i<p; i++) {
            if (isBlack(i)) {
                allWhite = false;
                break;
            }
        }
        if (allWhite) ret++;
    }
    cout << ret << endl;
}