#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long int;

priority_queue<lld, vector<lld>, greater<lld>> minHeap;

int main() {
    int n, m; cin >> n >> m;
    while(n--) {
        int x; cin >> x;
        minHeap.push(x);
    }
    while(m--) {
        lld x = minHeap.top(); minHeap.pop();
        lld y = minHeap.top(); minHeap.pop();
        minHeap.push(x+y); minHeap.push(x+y);
    }

    lld ret = 0;
    while(!minHeap.empty()) {
        ret += minHeap.top();
        minHeap.pop();
    }
    cout << ret << endl;
}