#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

int k, n;
vector<lld> A;

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};

// signals중 합이 k인 부분 수열의 개수
int solve() {
    int ret = 0;
    RNG rng;
    deque<int> signalQueue;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int sign = rng.next();
        cout << sum << endl;
        if (sum < k) {
            sum += sign;
            signalQueue.push_back(sign);
        } else if (sum == k) ret++;
        sum -= signalQueue.front();
        signalQueue.pop_front();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        cin >> k >> n;
        // cout << k << endl;
        cout << solve() << endl;
    }
}