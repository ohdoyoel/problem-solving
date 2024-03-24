#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long int;

priority_queue<lld, vector<lld>, greater<lld>> minHeap;

int main() {
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        while(k--) {
            int x; cin >> x;
            minHeap.push(x);
        }

        lld ret = 0;
        while(minHeap.size() > 1) {
            lld x = minHeap.top(); minHeap.pop();
            lld y = minHeap.top(); minHeap.pop();
            minHeap.push(x+y); ret += (x+y);
        }
        minHeap.pop();
        cout << ret << endl;
    }
}