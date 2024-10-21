#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1000001], next[1000001];

int toOne(int n) {
    int& ret = cache[n];
    if (ret!=-1) return ret;

    ret = 987654321;
    int step = -1;
    if (ret > 1+toOne(n/3)) {
        ret = 1+toOne(n/3);
        step = n/3;
    }
    if (ret > 1+toOne(n/2)) {
        ret = 1+toOne(n/2);
        step = n/2;
    }
    if (ret > 1+toOne(n-1)) {
        ret = 1+toOne(n-1);
        step = n-1;
    }
    next[n] = step;
    return ret;
}

void showStep(int x) {
    cout << x << ' ';
    if (next[x]!=-1) showStep(next[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    memset(next, -1, sizeof(next));
    int x; cin >> x;
    cout << toOne(x) << endl;
    showStep(x);
}