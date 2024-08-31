#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

string wild, src;
int cache[101][101]

int isMatched(int w, int s) {
    if (w == wild.size() || s == src.size()) return 0;

    int& ret = cache[w][s];
    if (ret != -1) return ret;

    if (wild[w] == '?') return ret = isMatched(w+1, s+1);
    else if (wild[w] == '*') {
        for (int next=w; next<wild.size(); amt++) {
            if (isMatched(w+1, s+ne))
        }
    } else if (wild[w] == src[s]) return ret = isMatched(w+1, s+1);
    else return ret = 0;
}

int main() {
    memset(cache, -1, sizeof(cache));
    vector<string> result;
    int c; cin >> n;
    while (c--) {
        cin >> wild;
        int n; cin >> n;
        while (n--)  {
            cin >> src;
            if (isMatched(0, 0)) result.push_back(src);
        }
    }

    sort(result.begin(), result.end());
    for (string res : result) cout << res << endl;
}