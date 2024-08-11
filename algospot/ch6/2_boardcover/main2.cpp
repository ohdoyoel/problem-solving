#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int ret;
int h, w;
vector<vector<bool>> isBoardCovered;

void printBoard() {
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (isBoardCovered[i][j]) cout << '#';
      else cout << '.';
    }
    cout << endl;
  }
}

void solve() {
    int firstFreeR = -1;
    int firstFreeC = -1;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (!isBoardCovered[i][j]) {
                firstFreeR = i;
                firstFreeC = j;
                break;
            }
        }
        if (firstFreeR != -1) break;
    }
    if (firstFreeR == -1) {
        ret++;
        return;
    }
    
    // .SB
    //  B
    if (firstFreeR+1<h && firstFreeC+1<w && !isBoardCovered[firstFreeR+1][firstFreeC] && !isBoardCovered[firstFreeR][firstFreeC+1]) {
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC] = isBoardCovered[firstFreeR][firstFreeC+1] = true;
        solve();
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC] = isBoardCovered[firstFreeR][firstFreeC+1] = false;
    }
    
    // .S
    // BB
    if (firstFreeR+1<h && 0<=firstFreeC-1 && !isBoardCovered[firstFreeR+1][firstFreeC] && !isBoardCovered[firstFreeR+1][firstFreeC-1]) {
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC-1] = true;
        solve();
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC-1] = false;
    }

    // .S
    //  BB
    if (firstFreeR+1<h && firstFreeC+1<w && !isBoardCovered[firstFreeR+1][firstFreeC] && !isBoardCovered[firstFreeR+1][firstFreeC+1]) {
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC+1] = true;
        solve();
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC] = isBoardCovered[firstFreeR+1][firstFreeC+1] = false;
    }

    // .SB
    //   B
    if (firstFreeR+1<h && firstFreeC+1<w && !isBoardCovered[firstFreeR][firstFreeC+1] && !isBoardCovered[firstFreeR+1][firstFreeC+1]) {
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR][firstFreeC+1] = isBoardCovered[firstFreeR+1][firstFreeC+1] = true;
        solve();
        isBoardCovered[firstFreeR][firstFreeC] = isBoardCovered[firstFreeR][firstFreeC+1] = isBoardCovered[firstFreeR+1][firstFreeC+1] = false;
    }
}

int main() {
    int c; cin >> c;
    while(c--) {
        cin >> h >> w;        
        isBoardCovered.resize(h);
        for (int i=0; i<h; i++) {
            isBoardCovered[i].resize(w);
            string s; cin >> s;
            for (int j=0; j<w; j++) isBoardCovered[i][j] = (s[j] == '#');
        }

        ret = 0;
        solve();
        cout << ret << endl;
    }
}