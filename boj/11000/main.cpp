#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int,int>;

multimap<int,int> st;

int main() {
    int n; cin >> n;
    while (n--) {
        int s, t; cin >> s >> t;
        st.insert(make_pair(s, t));
    }

    int ret = 0;
    for (auto it=st.begin(); it!=st.end(); it++) {
        auto next = st.lower_bound(it->second);
        if (next == st.end()) ret++;
    }
    cout << ret << endl;
}