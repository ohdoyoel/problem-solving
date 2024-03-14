#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<set<int>> sets;

bool isContains(int a, int b) {
    for (int i=0; i<sets.size(); i++) {
        if (sets[i].find(a) != sets[i].end() && sets[i].find(b) != sets[i].end()) return true;
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m; sets.resize(n+1);
    for (int i=0; i<=n; i++) sets[i].insert(i);

    while(m--) {
        int c, a, b; cin >> c >> a >> b;
        switch (c) {
            case 0:
            {
                int aIdx = -1;
                int bIdx = -1;
                for (int i=0; i<sets.size(); i++) {
                    if (sets[i].find(a) != sets[i].end()) {
                        aIdx = i; break;
                    }
                }
                for (int i=0; i<sets.size(); i++) {
                    if (sets[i].find(b) != sets[i].end()) {
                        bIdx = i; break;
                    }
                }
                if (aIdx > bIdx) {
                    int tmp = bIdx;
                    bIdx = aIdx;
                    aIdx = tmp;
                }
                sets[aIdx].merge(sets[bIdx]);
                if (aIdx != bIdx) sets[bIdx].clear();
                break;
            }
            case 1:
            {
                if(isContains(a, b)) cout << "YES" << endl;
                else cout << "NO" << endl;
                break;
            }
        }
    }
}