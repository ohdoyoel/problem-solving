#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1002], choices[1002];
int n;
vector<int> A;

int lis(int i) {
    int& ret = cache[i+1];
    if (ret!=-1) return ret;

    ret = 1;
    int lisIndex = -1;
    for (int j=i+1; j<n; j++) {
        if (i==-1 || A[j]>A[i]) {
            int cand = 1+lis(j);
            if (cand > ret) {
                ret = cand;
                lisIndex = j;
            }
        }
    }
    choices[i+1] = lisIndex;
    return ret;
}

void showLis(int i) {
    cout << A[choices[i+1]] << endl;
    int next = choices[choices[i+1]];
    if (next!=-1) showLis(next);
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n; A.resize(n);
    for (int i=0; i<n; i++) cin >> A[i];
    cout << lis(-1) << endl;
    showLis(-1);
}