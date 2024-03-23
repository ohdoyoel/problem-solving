#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        minHeap.push(x);
    }

    if (minHeap.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ret = 0;
    while (minHeap.size() != 1) {
        int comb;
        comb = minHeap.top(); minHeap.pop();
        comb += minHeap.top(); minHeap.pop();
        ret += comb;
        minHeap.push(comb);
    }
    cout << ret << endl;
}