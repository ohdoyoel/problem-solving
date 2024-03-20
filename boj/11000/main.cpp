#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int,int>;

struct compSF {
    bool operator() (pii a, pii b) { return a->second < b->first; }
};

prioirity_queue<pii, vector<pii>, compSF> st;

int main() {
    int n; cin >> n;
    while (n--) {
        int s, t; cin >> s >> t;
        st.push(make_pair(s, t));
    }

    for (pii s : st) cout << st.first << " " st.second << endl;
}