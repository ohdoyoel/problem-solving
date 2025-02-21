#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, dist;
vector<int> P, D;
int C[100001][1000000001];

int cost(int i, int fuel) {
    if (i==static_cast<int>(P.size()-1)) return 0;

    int& ret = C[i][fuel];
    ret = 987654321;
    for (int f=dist-fuel; f>=0 && fuel+f>=D[i]; --f) {
        ret = min(ret, P[i]*f + cost(i+1, fuel+f-D[i]));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; P.resize(n); D.resize(n-1);
    for (int i=0; i<n-1; ++i) cin >> D[i];
    dist=0;
    for (int i=0; i<n-1; ++i) dist += D[i];
    for (int i=0; i<n; ++i) cin >> P[i];
    cout << cost(0, 0) << endl;
    return 0;
}