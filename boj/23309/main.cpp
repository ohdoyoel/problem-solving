#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

list<int>::iterator stationToIt[1000001];
list<int> stations;
list<int>::iterator it;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    int n, m; cin >> n >> m;
    while(n--) {
        int c; cin >> c;
        stations.push_back(c);
        stationToIt[c] = next(stations.end(), -1);
    }

    while(m--) {
        string cmd; cin >> cmd;
        if (cmd == "BN"){
            int i, j; cin >> i >> j;
            it = stationToIt[i];
            ++it;
            if (it == stations.end()) it = stations.begin();
            cout << *it << endl;
            it = stations.insert(it, j);
            stationToIt[j] = it;
        } else if (cmd == "BP") {
            int i, j; cin >> i >> j;
            it = stationToIt[i];
            if (it == stations.begin()) it = stations.end();
            --it;
            cout << *it << endl;
            ++it;
            if (it == stations.end()) it = stations.begin();
            it = stations.insert(it, j);
            stationToIt[j] = it;
        } else if (cmd == "CN") {
            int i; cin >> i;
            it = stationToIt[i];
            ++it;
            if (it == stations.end()) it = stations.begin();
            cout << *it << endl;
            stationToIt[*it] = stationToIt[0];
            it = stations.erase(it);
        } else if (cmd == "CP") {
            int i; cin >> i;
            it = stationToIt[i];
            if (it == stations.begin()) it = stations.end();
            --it;
            cout << *it << endl;
            stationToIt[*it] = stationToIt[0];
            it = stations.erase(it);
        }
    }
}