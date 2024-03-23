#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int,int>;
using lld = long long int;
struct compMV {
    bool operator() (pii a, pii b) { return a.second == b.second ? a.first > b.first : a.second < b.second; }
};

priority_queue<pii, vector<pii>, compMV> heap;
multiset<int> bag;

int main() {
    int n, k; cin >> n >> k;
    while(n--) {
        int m, v; cin >> m >> v;
        heap.push(make_pair(m, v));
    }
    // while(!heap.empty()) {
    //     cout << heap.top().first << " " << heap.top().second << endl;
    //     heap.pop();
    // }

    while(k--) {
        int c; cin >> c;
        bag.insert(c);
    }

    lld ret = 0;
    while(!heap.empty()) {
        pii top = heap.top(); heap.pop();
        auto optBagIt = bag.lower_bound(top.first);
        if (optBagIt == bag.end()) continue;
        ret += top.second;
        bag.erase(optBagIt);
    }
    cout << ret << endl;
}