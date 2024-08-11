#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> clocksFrom[10] = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};
vector<int> clocks(16);
int ret;

bool clocksAllNoon() {
    bool ret = true;
    for (int clock : clocks) if (clock!=12) ret = false;
    return ret;
}

void plusClock(int clock, int time) {
    int temp = clocks[clock] + 3*time;
    while (12<temp) temp-=12;
    clocks[clock] = temp;
}

void minusClock(int clock, int time) {
    int temp = clocks[clock] - 3*time;
    while (temp<=0) temp+=12;
    clocks[clock] = temp;
}

void solve(int s, int times) {
    if (clocksAllNoon()) {
        ret = min(ret, times);
        return;
    }
    if (s == 10) return;

    for (int t=0; t<4; t++) {
        for (int c : clocksFrom[s]) plusClock(c, t);
        solve(s+1, times+t);
        for (int c : clocksFrom[s]) minusClock(c, t);
    }
}

int main() {
    int c; cin >> c;
    while(c--) {
        for (int i=0; i<16; i++) {
            int h; cin >> h;
            clocks[i] = h;
        }
        
        ret = 50;
        solve(0, 0);
        if (ret == 50) cout << -1 << endl;
        else cout << ret << endl;
    }

}