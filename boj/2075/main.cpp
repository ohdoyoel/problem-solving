#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct compDq {
    bool operator()(deque<int> a, deque<int> b) { return a.back() < b.back(); }
};

priority_queue<deque<int>, vector<deque<int>>, compDq> dqHeap;
vector<deque<int>> input;

int main() {
    int n; cin >> n; input.resize(n);
    for (int i=0; i<n; i++) {
        input[i].resize(n);
        for (int j=0; j<n; j++) cin >> input[j][i];
    }
    for (deque<int> dq : input) dqHeap.push(dq);
    
    // for (int d : dqHeap.top()) cout << d << endl;
    
    n--;
    while(n--) {
        deque<int> top = dqHeap.top(); dqHeap.pop();
        top.pop_back(); dqHeap.push(top);
    }

    cout << dqHeap.top().back() << endl;
}