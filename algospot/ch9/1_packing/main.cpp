#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][1001], choice[101][1001][2];
int n;
vector<string> name;
vector<int> weight;
vector<int> nd;
vector<int> picked;
vector<string> result;

int needs(int i, int w) {
    int& ret = cache[i+1][w];
    if (ret!=-1) return ret;

    ret = 0;
    int bestNext = -1;
    int bestWeight = -1;
    for (int j=i; j<n; ++j) {
        if (!picked[j] && weight[j] <= w) {
            picked[j] = true;
            int cand = nd[j] + needs(j, w-weight[j]);
            picked[j] = false;
            if (ret < cand) {
                ret = cand;
                bestNext = j;
                bestWeight = w-weight[j];
            }
        }
    }
    choice[i+1][w][0] = bestNext;
    choice[i+1][w][1] = bestWeight;
    return ret;
}

void show(int i, int w) {
    if (i!=-1) result.push_back(name[i]);
    int next = choice[i+1][w][0];
    int weight = choice[i+1][w][1];
    if (next!=-1 && weight!=-1) show(next, weight);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        memset(cache, -1, sizeof(cache));
        memset(choice, -1, sizeof(choice));
        int w; cin >> n >> w; name.resize(n); weight.resize(n); nd.resize(n); picked.resize(n);
        for (int i=0; i<n; ++i) cin >> name[i] >> weight[i] >> nd[i];
        
        result.clear();
        cout << needs(-1, w) << ' ';
        show(-1, w);
        cout << result.size() << endl;
        for (string res : result) cout << res << endl;
    }
}