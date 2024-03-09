#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

int k, n;
lld A[50000001];
vector<int> signals;

int sumQueue(deque<int> q) {
    int sum = 0;
    for (int i = 0; i < q.size(); ++i) {
        // cout << q[i] << " ";
        sum += q[i];
    }
    cout << endl;
    return sum;
}

// signals중 합이 k인 부분 수열의 개수
int solve() {
    int ret = 0;
    deque<int> signalQueue;

    for (int i = 0; i < n; ++i) {
        if (sumQueue(signalQueue) < k) { 
            signalQueue.push_back(signals[i]);
            continue;
        }
        else if (sumQueue(signalQueue) == k) ret++;
        signalQueue.pop_front();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    A[0] = 1983;
    for (int i = 1; i < 50000001; ++i) if (A[i] == 0) A[i] = ((A[i-1] * 214013 + 2531011) % 4294967296);
    int c; cin >> c;
    while (c--) {
        cin >> k >> n; signals.resize(n);
        for (int i = 0; i < n; ++i) signals[i] = A[i] % 10000 + 1;
        cout << solve() << endl;
    }
}