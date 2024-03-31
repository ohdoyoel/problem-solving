#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef pair<int,int> pii;

int n, m;
vector<vector<bool>> picture, visited;

int dfsPicture(int x, int y) {
    visited[x][y] = true;
    int ret = 1;
    if (0<x && !visited[x-1][y] && picture[x-1][y]) ret+=dfsPicture(x-1,y);
    if (x<n-1 && !visited[x+1][y] && picture[x+1][y]) ret+=dfsPicture(x+1,y);
    if (0<y && !visited[x][y-1] && picture[x][y-1]) ret+=dfsPicture(x,y-1);
    if (y<m-1 && !visited[x][y+1] && picture[x][y+1]) ret+=dfsPicture(x,y+1);
    return ret;
}

pii dfsCntPicture() {
    int cnt = 0;
    int maxPic = 0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            if (!visited[x][y] && picture[x][y]) {
                cnt++;
                maxPic = max(maxPic, dfsPicture(x,y));
            }
        }
    }
    return make_pair(cnt, maxPic);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m; picture.resize(n); visited.resize(n);
    for (int i=0; i<n; i++) {
        picture[i].resize(m); visited[i].resize(m);
        for (int j=0; j<m; j++) {
            int x; cin >> x;
            picture[i][j] = (x==1);
        }
    }
    pii ret = dfsCntPicture();
    cout << ret.first << endl << ret.second << endl;
}