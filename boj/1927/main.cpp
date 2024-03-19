#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        if (x == 0) {
            if (minHeap.empty()){
                cout << 0 << endl;
                continue;
            }
            cout << minHeap.top() << endl;
            minHeap.pop();
        } else minHeap.push(x);
    }
}