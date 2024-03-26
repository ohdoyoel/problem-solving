#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef short int si;

int n;
si board[3][3];

bool solve(int x, int y) {
    if (x>=n || y>=n) return false;
    si step = board[x][y];
    if (step == 0) return false;
    else if (step == -1) return true;
    return solve(x+step, y) || solve(x, y+step);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> board[i][j];
    }

    if (solve(0, 0)) cout << "HaruHaru" << endl;
    else cout << "Hing" << endl;
}