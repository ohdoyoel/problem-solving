#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

string wild, src;
int cache[101][101];

int isMatched(int w, int s) {
    if (w == wild.size()) return s == src.size();

    int& ret = cache[w][s];
    if (ret != -1) return ret;

    if (wild[w] == '?' || wild[w] == src[s]) return ret = isMatched(w+1, s+1);
    else if (wild[w] == '*') for (int next=s; next<=src.size(); next++) if (isMatched(w+1, next)) return ret = 1;
    
    return ret = 0;
}

int main() {
    vector<string> result;
    int c; cin >> c;
    while (c--) {
        cin >> wild;
        int n; cin >> n;
        while (n--)  {
            cin >> src;
            memset(cache, -1, sizeof(cache));
            if (isMatched(0, 0)) result.push_back(src);
        }
    }

    sort(result.begin(), result.end());
    for (string res : result) cout << res << endl;
}