#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isDominated(map<int,int>& coords, int x, int y) {
    auto it = coords.lower_bound(x);
    if (it == coords.end()) return false;
    return y < it->second;
}

void removeDominated(map<int,int>& coords, int x, int y) {
    auto it = coords.lower_bound(x);
    if (it == coords.begin()) return;
    it--;
    while(it->second < y) {
        coords.erase(it);
        if (it == coords.begin()) break;
        else it--;
    }
}

int coordsSize(map<int,int>& coords, int x, int y) {
    if (isDominated(coords, x, y)) return coords.size();
    removeDominated(coords, x, y);
    coords[x] = y;
    return coords.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        int n; cin >> n;
        map<int,int> coords;
        int res = 0;
        while(n--) {
            int x, y; cin >> x >> y;
            res += coordsSize(coords, x, y);
        }
        cout << res << endl;
    }
}