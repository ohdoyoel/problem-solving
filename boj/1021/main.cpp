#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m;
deque<int> q;

int main() {
    cin >> n >> m; q.resize(n);
    for (int p = 1; p <= m; ++p) {
        int idx; cin >> idx;
        q[idx-1] = p;
    }

    int ret = 0;
    
    for (int p = 1; p <= m; ++p) {
        int idx = 0;
        for (int i = 0; i < q.size(); ++i) {
            if (q[i] == p) { idx=i; break; }
        }

        if (idx <= q.size()/2) {
            for (int i = 0; i < idx; ++i) {
                q.push_back(q.front());
                q.pop_front();
                ret++;
            }
        } else {
            for (int i = 0; i < q.size()-idx; ++i) {
                q.push_front(q.back());
                q.pop_back();
                ret++;
            }
        }
        q.pop_front();
    }
    
    cout << ret << endl;
}