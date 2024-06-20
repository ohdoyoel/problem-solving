#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<bool>> A;

int n;

void fillA(int x, int y, int s) {
    if (x>=4*n-3 || y>=4*n-3) return;
    
    for (int dx=0; dx<4*s-3; dx++) A[x+dx][y] = true;
    for (int dx=0; dx<4*s-3; dx++) A[x+dx][y+4*s-4] = true;
    for (int dy=0; dy<4*s-3; dy++) A[x][y+dy] = true;
    for (int dy=0; dy<4*s-3; dy++) A[x+4*s-4][y+dy] = true;
    fillA(x+2,y+2,s-1);
}

void printA() {
    for (vector<bool> ARow : A) {
        for (bool isAStar : ARow) {
            if (isAStar) cout<<'*';
            else cout<<' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    A.resize(4*n-3);
    for (int i=0; i<A.size(); i++) A[i].resize(4*n-3);
    fillA(0, 0, n);
    printA();
}