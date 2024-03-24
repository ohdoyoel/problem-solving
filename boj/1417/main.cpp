#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

priority_queue<int, vector<int>, less<int>> maxHeap;

int main() {
    int n; cin >> n;
    int first; cin >> first;
    n--;
    while (n--) {
        int x; cin >> x;
        maxHeap.push(x);
    }

    int ret = 0;
    while(!maxHeap.empty() && maxHeap.top() >= first) {
        int top = maxHeap.top(); maxHeap.pop();
        top--; maxHeap.push(top);
        first++;
        ret++;
    }
    cout << ret << endl;
}