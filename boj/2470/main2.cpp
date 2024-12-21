#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;
pair<int, int> answer;

void solve() {
    sort(A.begin(), A.end());
    int start = 0;
    int end = n-1;
    int min = 2000000001;
    while (start < end) {
        int res = A[start] + A[end];
        if (abs(res) < min) {
            min = abs(res);
            answer = {A[start], A[end]};
        }
        if (res < 0) start++;
        else end--;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i]; 
    solve();
    cout << answer.first << ' ' << answer.second << endl;
}