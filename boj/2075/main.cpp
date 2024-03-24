#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct compDa {
    bool operator()(vector<int> a, vector<int> b) { return a.back() < b.back(); }
};

priority_queue<vector<int>, vector<vector<int>>, compDa> daHeap;
vector<vector<int>> input;

int main() {
    int n; cin >> n; input.resize(n);
    for (int i=0; i<n; i++) {
        input[i].resize(n);
        for (int j=0; j<n; j++) cin >> input[j][i];
    }
    for (vector<int> da : input) daHeap.push(da);
    
    // for (int d : dqHeap.top()) cout << d << endl;
    
    n--;
    while(n--) {
        vector<int> top = daHeap.top(); daHeap.pop();
        top.pop_back(); daHeap.push(top);
    }

    cout << daHeap.top().back() << endl;
}