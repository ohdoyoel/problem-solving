#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int k;
vector<string> ss;
int overlap[15][15];
int cache[16][1<<15];

int overlapLen(string& a, string& b) {
    int maxLen = min(a.size(), b.size());
    if (a.find(b)!=string::npos || b.find(a)!=string::npos) return maxLen;
    for (int len=maxLen; len>=0; --len) if (a.substr(a.size()-len) == b.substr(0, len)) return len;
}

int restore(int last, int used) {
    if (used == (1<<k)-1) return 0;

    int& ret = cache[last+1][used];
    if (ret != -1) return ret;

    ret = 0;
    for (int next=0; next<k; ++next) {
        if (last == -1) ret = max(ret, restore(next, used | (1<<next)));
        else if ((used & (1<<next)) == 0) {
            ret = max(ret, overlap[last][next] + restore(next, used | (1<<next)));
        }
    }
    return ret;
}

string reconstruct(int last, int used) {
    if (used == (1<<k)-1) return "";
    for (int next=0; next<k; ++next) {
        if (used & (1<<next)) continue;
        int ifUsed = last==-1 ? restore(next, used|(1<<next)) : restore(next, used|(1<<next)) + overlap[last][next];
        if (ifUsed == restore(last, used)) return last==-1 ? ss[next]+reconstruct(next, used|(1<<next)) : ss[next].substr(overlap[last][next])+reconstruct(next, used|(1<<next));
    }
    return "**oops**";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        cin >> k; ss.resize(k);
        int n = 0;
        for (int i=0; i<k; ++i) {
            cin >> ss[i];
            n += ss[i].size();
        }
        for (int i=0; i<k; ++i) for (int j=0; j<k; ++j) overlap[i][j] = overlapLen(ss[i], ss[j]);
        // for (int i=0; i<k; ++i){
        //   for (int j=0; j<k; ++j) cout << overlap[i][j] << ' ';
        //   cout << endl;
        // }
        // cout << n - restore(-1, 0) << endl;
        cout << reconstruct(-1, 0) << endl;
    }
}