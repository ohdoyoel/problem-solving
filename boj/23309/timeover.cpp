#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

list<int> stations;
auto it = stations.begin();

int main() {
    int n, m; cin >> n >> m;
    while(n--) {
        int c; cin >> c;
        stations.push_back(c);
    }

    while(m--) {
        string cmd; cin >> cmd;
        if (cmd == "BN"){
            int i, j; cin >> i >> j;
            while(*it != i) {
                ++it;
                if (it == stations.end()) it = stations.begin();
            }
            ++it;
            if (it == stations.end()) it = stations.begin();
            cout << *it << endl;
            stations.insert(it, j);
        } else if (cmd == "BP") {
            int i, j; cin >> i >> j;
            while (*it != i) {
                ++it;
                if (it == stations.end()) it = stations.begin();
            }
            if (it == stations.begin()) it = stations.end();
            --it;
            cout << *it << endl;
            ++it;
            if (it == stations.end()) it = stations.begin();
            stations.insert(it, j);
        } else if (cmd == "CN") {
            int i; cin >> i;
            while (*it != i) {
                it++;
                if (it == stations.end()) it = stations.begin();
            }
            it++;
            if (it == stations.end()) it = stations.begin();
            cout << *it << endl;
            it = stations.erase(it);
        } else if (cmd == "CP") {
            int i; cin >> i;
            while (*it != i) {
                it++;
                if (it == stations.end()) it = stations.begin();
            }
            if (it == stations.begin()) it = stations.end();
            it--;
            cout << *it << endl;
            it = stations.erase(it);
        }
    }
}