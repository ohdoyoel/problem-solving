#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        priority_queue <int, vector<int>, less<int>> maxHeap;
        priority_queue <int, vector<int>, greater<int>> minHeap;
        int m; cin >> m;
        cout << (m+1)/2 << endl;
        for (int i=1; i<=m; i++) {
            int x; cin >> x;
            if (maxHeap.size() == minHeap.size()) maxHeap.push(x);
            else minHeap.push(x);
            if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
                int mx = maxHeap.top(); maxHeap.pop();
                int mn = minHeap.top(); minHeap.pop();
                minHeap.push(mx); maxHeap.push(mn);
            }
            if (i%2) cout << maxHeap.top() << " ";
            if (!(i%20)) cout << endl;
        }
        cout << endl;
    }
}