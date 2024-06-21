#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<vector<int>> A;

int pulling(int x, int y, int s) {
    if (s==1) return A[x][y];

    vector<int> temp;
    temp.push_back(pulling(x, y, s/2));
    temp.push_back(pulling(x, y+s/2, s/2));
    temp.push_back(pulling(x+s/2, y, s/2));
    temp.push_back(pulling(x+s/2, y+s/2, s/2));
    sort(all(temp), greater<int>());

    return temp[1];
}

int main() {
    int n; cin >> n; A.resize(n);
    for (int i=0; i<n; i++) A[i].resize(n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> A[i][j];
    }


    cout << pulling(0, 0, n) << endl;
}