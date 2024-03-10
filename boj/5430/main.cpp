#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

deque<string> x;
string p;
int n;

void solve() {
    bool frontPop = true;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == 'R') frontPop = !frontPop;
        else if (x.empty()) {
            cout << "error" << endl;
            return;
        } else if (frontPop) x.pop_front();
        else x.pop_back();
    }

    cout << "[";
    if (frontPop) {
        if (!x.empty()) {
            cout << x.front();
            x.pop_front();
        }
        for (; !x.empty(); x.pop_front()) cout << "," << x.front();
    } else {
        if (!x.empty()) {
            cout << x.back();
            x.pop_back();
        }
        for (; !x.empty(); x.pop_back()) cout << "," << x.back();
    }
    cout << "]" << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        x.clear();
        cin >> p;cin >> n;
        string xs; cin >> xs;
        int i = 0;
        while (i < xs.size()) {
            if ("[,]"s.find(xs[i]) == -1) {
                int next;
                for (int j = i; j < xs.size(); ++j) {
                    if ("[,]"s.find(xs[j]) != -1) {
                        next = j;
                        break;
                    }
                }
                x.push_back(xs.substr(i, next-i));
                i = next;
            }
            i++;
        }
        solve();
    }
}