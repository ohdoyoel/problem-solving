#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> Q; // Q[i] = j, 퀸은 (i, j)에 있음.

bool placable(int x, int y) {
    for (int i=0; i<n; ++i) if (Q[i]!=-1 && (x==i || y==Q[i] || abs(x-i)==abs(y-Q[i]))) return false;
    return true;
}

// r번째 행을 채우고 개수 반환
int fill(int r) {
    if (r==n) return 1;
    
    int ret = 0;
    for (int c=0; c<n; ++c) {
        if (placable(r, c)) {
            Q[r] = c;
            ret += fill(r+1);
            Q[r] = -1;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; Q.resize(n);
    for (int i=0; i<n; ++i) Q[i] = -1;
    cout << fill(0) << endl;
}