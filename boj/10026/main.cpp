#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
// R0 G1 B2;
vector<vector<short>> picture;
vector<vector<bool>> visited;

void dfsByNormal(int x, int y) {
    if (x>n-1 || y>n-1) return;

    visited[x][y] = true;
    int color = picture[x][y];
    if (0<x && !visited[x-1][y] && picture[x-1][y]==color) dfsByNormal(x-1, y);
    if (x<n-1 && !visited[x+1][y] && picture[x+1][y]==color) dfsByNormal(x+1, y);
    if (0<y && !visited[x][y-1] && picture[x][y-1]==color) dfsByNormal(x, y-1);
    if (y<n-1 && !visited[x][y+1] && picture[x][y+1]==color) dfsByNormal(x, y+1);
    return;
}

int dfsCntByNormal() {
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) visited[i][j] = false;
    }

    int ret = 0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            if (!visited[x][y]) {
                ret++;
                dfsByNormal(x, y);
            }
        }
    }
    return ret;
}

void dfsByPatient(int x, int y) {
    if (x>n-1 || y>n-1) return;

    visited[x][y] = true;
    int color = picture[x][y];
    if (0<x && !visited[x-1][y] && (picture[x-1][y]==color
        || (color==0 && picture[x-1][y]==1) || color==1 && picture[x-1][y]==0)) dfsByPatient(x-1, y);
    if (x<n-1 && !visited[x+1][y] && (picture[x+1][y]==color
        || (color==0 && picture[x+1][y]==1) || color==1 && picture[x+1][y]==0)) dfsByPatient(x+1, y);
    if (0<y && !visited[x][y-1] && (picture[x][y-1]==color
        || (color==0 && picture[x][y-1]==1) || color==1 && picture[x][y-1]==0)) dfsByPatient(x, y-1);
    if (y<n-1 && !visited[x][y+1] && (picture[x][y+1]==color
        || (color==0 && picture[x][y+1]==1) || color==1 && picture[x][y+1]==0)) dfsByPatient(x, y+1);
    return;
}

int dfsCntByPatient() {
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) visited[i][j] = false;
    }

    int ret = 0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            if (!visited[x][y]) {
                ret++;
                dfsByPatient(x, y);
            }
        }
    }
    return ret;
}

int main() {
    cin >> n; picture.resize(n); visited.resize(n);
    for (int i=0; i<n; i++) {
        string line; cin >> line;
        picture[i].resize(n); visited[i].resize(n);
        for (int j=0; j<n; j++) picture[i][j] = line[j] == 'R' ? 0 : (line[j] == 'G' ? 1 : (line[j] == 'B' ? 2 : 4));
    }

    cout << dfsCntByNormal() << " " << dfsCntByPatient() << endl;
}