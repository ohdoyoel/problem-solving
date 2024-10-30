#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

double cache[102][502];
int choice[102][502];
int n, m, q;
vector<string> word;
vector<int> R;
vector<double> B;
vector<vector<double>> T, M;

double recognize(int i, int prev) {
    if (i==n) return 0.0f;

    double& ret = cache[i][prev+1];
    if (ret != 1.0) return ret;

    ret = -1e200;
    for (int j=0; j<m; j++) {
        double cand = (prev == -1 ? B[j] : T[prev][j])  + M[j][R[i]] + recognize(i+1, j);
        if (ret < cand) {
            ret = cand;
            choice[i][prev+1] = j;
        }
    }
    return ret;
}

void showChoice(int i, int prev) {
    int choose = choice[i][prev+1];
    if (choose != -1) {
        cout << word[choose] << ' ';
        showChoice(i+1, choose);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> q; word.resize(m); B.resize(m); T.resize(m); M.resize(m);
    for (int i=0; i<m; ++i) cin >> word[i];
    for (int i=0; i<m; ++i) cin >> B[i];
    for (int i=0; i<m; ++i) {
        T[i].resize(m);
        for (int j=0; j<m; ++j) cin >> T[i][j];
    }
    for (int i=0; i<m; ++i) {
        M[i].resize(m);
        for (int j=0; j<m; ++j) cin >> M[i][j];
    }

    while (q--) {
        memset(choice, -1, sizeof(choice));
        for (int i=0; i<102; ++i) for (int j=0; j<502; ++j) cache[i][j] = 1.0;
        cin >> n; R.resize(n);
        for (int i=0; i<n; ++i) {
            string w; cin >> w;
            for (int j=0; j<m; ++j) if (w==word[j]) R[i] = j;
        }
        recognize(0, -1);
        showChoice(0, -1);
        cout << endl;
    }
}