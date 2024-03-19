#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int, int>;

struct compValue {
    bool operator() (pii a, pii b) { return a.second < b.second; }
};

priority_queue<int, vector<int>, less<int>> maxBag;
priority_queue<pii, vector<pii>, compValue> maxH;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k; cin >> n >> k;
    while(n--) {
        int m, v; cin >> m >> v;
        maxH.push(make_pair(m, v));
    }
    while(k--) {
        int k; cin >> k;
        maxBag.push(k);
    }

    int ret = 0;
    while(!maxH.empty() && !maxBag.empty()) {
        if (maxBag.top() >= maxH.top().first) {
            ret += maxH.top().second;
            maxBag.pop();
        }
        maxH.pop();
    }

    cout << ret << endl;
}