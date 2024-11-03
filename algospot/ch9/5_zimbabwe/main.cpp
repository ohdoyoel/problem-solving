#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
string e, cand;
int m;

int zimb(uint used) {
    if (used == ((1<<n)-1)) return stoi(cand)<stio(e) && stoi(cand)%m==0;

    int& ret = cache[used];
    if (ret!=-1) return ret;

    ret = 0;
    for (int next=0; next<n; ++next) {
        if (used & (1<<next)) continue;

        used |= (1<<next);
        cand += e[next];

        ret += zimb(used);

        used & ~(1<<next);
        cand.pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        val = '';
        cin >> e >> m; n = e.size();
        cout << zimb(0) << endl;
    }
}