#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n; 
int get(int state, int disc) { return (state >> (2 * disc)) & 3; }
int _set(int state, int disc, int value) { return (state & ~(3 << (2*disc))) | (value << (2*disc)); }
bool isEnd(int state) {
    for (int i=0; i<n-1; ++i) if (get(state, i)!=get(state,i+1)) return false;
    return true;
}

int solve(int begin) {
    int C[1<<(12*2)];
    memset(C, -1, sizeof(C));
    queue<int> Q;

    C[begin] = 0;
    Q.push(begin);

    while(!Q.empty()) {
        int here = Q.front(); Q.pop();
        if (isEnd(here)) return C[here];

        int top[4] = {-1, -1, -1, -1};
        for (int i=0; i<n; ++i) if (top[get(here, i)]==-1) top[get(here, i)] = i;

        for (int i=0; i<4; ++i) {
            if (top[i]==-1) continue;
            for (int j=0; j<4; ++j) {
                if (i==j) continue;
                if (top[j]==-1 || top[i]<top[j]) {
                    int there = _set(here, top[i], j);
                    if (C[there]==-1) {
                        C[there] = C[here] + 1;
                        Q.push(there);
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        int state = 0;
        for (int i=0; i<4; ++i) {
            cin >> n;
            for (int j=0; j<n; ++j) {
                int d; cin >> d;
                state = _set(state, d-1, i);
            }
        }
        cout << solve(state) << endl;
    }
    return 0;
}