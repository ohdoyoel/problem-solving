#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> Q;

bool fillable(int r, int c) {
    for (int i=0; i<r; ++i){
        if (Q[i]==c) return false;
        if (Q[i]==c-(r-i) || Q[i]==c+r-i) return false;
    }
    return true;
}

int solve(int r) {
    if (r==n) return 1;

    int ret = 0;
    for (int c=0; c<n; ++c) {
        if (Q[r]==-1 && fillable(r, c)) {
            Q[r] = c;
            ret += solve(r+1);
            Q[r] = -1;
        }
    }
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n; Q.resize(n);
    for (int i=0; i<n; ++i) Q[i] = -1;
    cout << solve(0) << endl;
}