#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct compAbs {
    bool operator()(int a, int b) return abs(a) > abs(b);
};

priority_queue<int, vector<int>, compAbs> absHeap;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        if (x == 0) {
            if (absHeap.empty()){
                cout << 0 << endl;
                continue;
            }
            cout << absHeap.top() << endl;
            absHeap.pop();
        } else absHeap.push(x);
    }
}