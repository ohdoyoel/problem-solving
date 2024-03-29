#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m;
vector<vector<bool>> isBlank;
vector<vector<bool>> visited;
int area;
vector<int> areas;

void dfsBlank(int x, int y) {
    area++;
    visited[x][y] = true;
    if (0<x && !visited[x-1][y] && isBlank[x-1][y]) dfsBlank(x-1, y);
    if (x<n-1 && !visited[x+1][y] && isBlank[x+1][y]) dfsBlank(x+1, y);
    if (0<y && !visited[x][y-1] && isBlank[x][y-1]) dfsBlank(x, y-1);
    if (y<m-1 && !visited[x][y+1] && isBlank[x][y+1]) dfsBlank(x, y+1);
}

int dfsCntBlank() {
    int ret = 0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            if (!visited[x][y] && isBlank[x][y]) {
                area = 0;
                ret++;
                dfsBlank(x, y);
                areas.push_back(area);
            }
        }
    }
    return ret;
}

int main() {
    cin>>m>>n; isBlank.resize(n); visited.resize(n);
    for (int i=0; i<n; i++) {
        isBlank[i].resize(m); visited[i].resize(m);
        for (int j=0; j<m; j++) {
            isBlank[i][j] = true;
            visited[i][j] = false;
        }
    }
    int k; cin >> k;
    while(k--) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        for (int x=x1; x<x2; x++) {
            for (int y=y1; y<y2; y++) isBlank[x][y]=false;
        }
    }

    cout << dfsCntBlank() << endl;
    sort(all(areas));
    for (int area : areas) cout << area << " ";
    cout << endl;
}