#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> elem;
// [원소] = 원소까지의 비교 최소 횟수
map<int,int> elemToMinComp;

int solve(int k) {
    if (k == 1) return elem[k-1] + elem[k];
    return elem[k] + 2 * solve(k-1);
}

int main() {
    int n; cin >> n; elem.resize(n);
    for (int i=0; i<n; i++) cin >> elem[i];

    sort(all(elem));

    cout << solve(n-1) << endl;
}