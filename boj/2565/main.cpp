#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;


vector<vector<bool>> connected;

// a~끝까지, b~끝까지 의 전봇대에서 교차하지 않기 위해 끊어야 하는 전깃줄의 최소 개수
int solve(int a, int b) {

}

int main() {
    int n; cin >> n;
    connected.resize(n+1);
    for (int i = 0; i < n; ++i) {
        connected[i].resize(n+1, false);
        int a, b; cin >> a >> b;
        connected[a][b] = true;
    }
}