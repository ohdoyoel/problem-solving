#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

priority_queue<int, vector<int> greater<int>> minHeap;

int main() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        minHeap.push(x);
    }

    int ret = minHeap.top(); minHeap.pop();
    ret += minHeap.top(); minHeap.pop();
    while(!minHeap.empty()) {
        ret *= 2;
        ret += minHeap.top(); minHeap.pop();
    }
    cout << ret << endl;
}