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
    while(!st.empty()){
        auto it = st.begin();
        while(true) {
            auto nxt = st.lower_bound(it->second);
            st.erase(it);
            if (nxt == st.end()) {
                ret++;
                break;
            }
            it = nxt;
        }
    }
    
    cout << ret << endl;
}