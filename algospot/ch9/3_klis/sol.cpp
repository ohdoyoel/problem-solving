#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[502], cacheCnt[502], S[500];

int lis(int start) {
    int& ret = cacheLen[start+1];
    if (ret!=-1) return ret;
    
    ret = 1;
    for (int next=start+1; next<n; ++next) if (start==-1 || S[next]>S[start]) ret = max(ret, 1+lis(next));
    return ret;
}

int count(int start) {
    if (lis(start)==1) return 1;

    int& ret = cacheCnt[start+1];
    if (ret!=-1) return ret;

    ret = 0;
    for (int next=start+1; next<n; ++next) if ((start==-1 || S[next]>S[start]) && 1+lis(next)==lis(start)) ret = min<long long>(MAX, (long long)ret+count(next));
    return ret;
}

void reconstruct(int start, int skip, vector<int>& ans) {
    if (start!=-1) ans.push_back(S[start]);

    vector<pair<int, int>> followers;
    for (int next=start+1; next<n; ++next) if ((start==-1 || S[next]>S[start]) && 1+lis(next)==lis(start)) followers.push_back(make_pair(S[next], next));
    sort(followers.begin(), followers.end());

    for (int i=0; i<followers.size(); ++i) {
        int idx = followers[i].second;
        int cnt = count(idx);
        if (skip >= cnt) skip -= cnt;
        else {
            reconstruct(idx, skip, ans);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        memset(cacheLen, -1, sizeof(cacheLen)); memset(cacheCnt, -1, sizeof(cacheCnt)); memset(S, 0, sizeof(S));
        int k; cin >> n >> k;
        for (int i=0; i<n; ++i) cin >> S[i];
        cout << lis(-1)-1 << endl;
        vector<int> ans;
        reconstruct(-1, k-1, ans);
        for (int& a : ans) cout << a << ' ';
        // cout << ans.size();
        cout << endl;
    }
}