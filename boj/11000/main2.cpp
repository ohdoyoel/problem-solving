#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

multimap<int, int> C;

int solve() {
    int ret = 0;
    while (!C.empty()) {
        auto it = C.begin();
        while (true) {
            auto next = C.lower_bound(it->second);
            if (next != C.end()) {
                C.erase(it);
                it = next;
            } else {
                ret++;
                break;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while(n--) {
        int s, t; cin >> s >> t;
        C.insert({s, t});
    }
    cout << solve() << endl;

    return 0;
}