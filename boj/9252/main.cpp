#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1001][1001], choice[1001][1001][2];
string A, B;

int lcs(int a, int b) {
    int& ret = cache[a][b];
    if (ret!=-1) return ret;

    ret = 0;
    int iMax = -1;
    int jMax = -1;
    for (int i=a; i<A.size(); ++i) {
        for (int j=b; j<B.size(); ++j) {
            if (A[i] == B[j]) {
                int cand = 1+lcs(i+1, j+1);
                if (ret < cand) {
                    ret = cand;
                    iMax = i;
                    jMax = j;
                }
            }
        }
    }
    choice[a][b][0] = iMax;
    choice[a][b][1] = jMax;
    return ret;
}

void showLcs(int i, int j) {
    cout << A[choice[i][j][0]];
    int aNext = choice[i][j][0]+1;
    int bNext = choice[i][j][1]+1;
    if (aNext<A.size() && bNext<B.size()) showLcs(aNext, bNext);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    memset(choice, -1, sizeof(choice));
    cin >> A >> B;
    cout << lcs(0, 0) << endl;
    showLcs(0, 0);
}