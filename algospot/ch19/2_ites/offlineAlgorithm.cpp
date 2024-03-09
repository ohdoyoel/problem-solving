#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

int k, n;
vector<lld> A;
vector<int> signals;

int sumQueue(vector<int> q) {
    int sum = 0;
    for (int i = 0; i < q.size(); ++i) sum += q[i];
    return sum;
}

// signals중 합이 k인 부분 수열의 개수
int solve() {
    int ret = 0;
    deque<int> signalQueue;

    for (int i = 0; i < n; ++i) {
        if (sumQueue(signalQueue) < k) signalQueue.push_back(signals[i]);
        else if (sumQueue(signalQueue) == k) ret++;
        else signalQueue.pop_front();
    }
    return ret;
}

int main() {
    int c; cin >> c;
    while (c--) {
        cin >> k >> n; A.resize(n); signals.resize(n);
        A[0] = 1983;
        for (int i = 1; i < n; ++i) if (A[i] == 0) A[i] = ((A[i-1] * 214013 + 2531011) % 4294967296);
        for (int i = 0; i < n; ++i) signals[i] = A[i] % 10000 + 1;
        cout << solve()
    }
}