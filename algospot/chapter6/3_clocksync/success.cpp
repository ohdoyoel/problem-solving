#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// variable
vector<int> clocks(16);
vector<int> switchConnectTo[10] = {
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

int switchPushed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void printClocks() {
    for (int i = 0; i < 16; ++i) {
        cout << clocks[i] << " ";
    }
    cout << endl;
}

void plusThreeInClocks(int idx) {
    if (clocks[idx] == 12) clocks[idx] = 3;
    else clocks[idx] += 3;
}

void minusThreeInClocks(int idx) {
    if (clocks[idx] == 3) clocks[idx] = 12;
    else clocks[idx] -= 3;
}

bool clocksAllNoon() {
    for (int i = 0; i < 16; ++i) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

// bool allSwitchPushedFewerThanFour() {
//     for (int i = 0; i < 10; ++i) {
//         if (switchPushed[i] >= 4) return false;
//     }
//     return true;
// }

int minCntForClockSync(int cnt, int startIdx) {
    // printClocks();
    
    if (clocksAllNoon()) return cnt;

    int ret = 123456789;
    for (int s = startIdx; s < 10; ++s) {
      if (switchPushed[s] >= 3) continue;
      switchPushed[s]++;
      for (int c : switchConnectTo[s]) {
          plusThreeInClocks(c);
      }
      int cand = minCntForClockSync(cnt + 1, s);
      ret = min(ret, cand);
      switchPushed[s]--;
      for (int c : switchConnectTo[s]) {
          minusThreeInClocks(c);
      }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while(c--) {
        for (int i = 0; i < 16; i++) {
            cin >> clocks[i];
        }

        int ans = minCntForClockSync(0, 0);
        if (ans == 123456789) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
