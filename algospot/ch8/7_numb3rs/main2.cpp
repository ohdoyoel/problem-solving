#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

double cache[101][51];
int n, p;
vector<vector<int>> isConnected;
vector<int> connections;

double prob(int day, int city) {
    if (day==0) return (city == p) ? 1.0 : 0.0;

    double & ret = cache[day][city];
    if (ret>=0) return ret;
    
    ret = 0.0;
    for (int c=0; c<n; c++) if (isConnected[city][c]) ret += prob(day-1, c) / connections[c];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int c; cin >> c;
    while (c--) {
        for (int i=0; i<101; i++) for (int j=0; j<51; j++) cache[i][j] = -1.0;
        int d; cin >> n >> d >> p; isConnected.resize(n); connections.resize(n);
        for (int i=0; i<n; i++) {
            isConnected[i].resize(n);
            connections[i] = 0;
            for (int j=0; j<n; j++) {
                cin >> isConnected[i][j];
                if (isConnected[i][j]) connections[i]++;
            }
        }
        int t; cin >> t;
        while (t--) {
            int q; cin >> q;
            cout << fixed << setprecision(8) << prob(d, q) << ' ';
        }
        cout << endl;
    }
    
    return 0;
}