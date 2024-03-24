#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lld;

int n, a, b;

struct RNG {
    int seed;
    RNG() : seed(1983) {}
    unsigned next() {
        int ret = seed;
        seed = ((seed * a) + b) % 20090711;
        return ret;
    }
};

int sumMedian(int n) {
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    RNG rng;

    int ret = 0;
    while(n--) {
        if (maxHeap.size() == minHeap.size()) maxHeap.push(rng.next());
        else minHeap.push(rng.next());
        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int mx = maxHeap.top(); maxHeap.pop();
            int mn = minHeap.top(); minHeap.pop();
            maxHeap.push(mn); minHeap.push(mx);
        }

        ret += maxHeap.top();
        ret %= 20090711;
    }
    return ret;
}


int main() {
    int c; cin >> c;
    while(c--) {
        cin >> n >> a >> b;
        cout << sumMedian(n) << endl;
    }
}