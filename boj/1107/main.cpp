#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
// A[0~9] 가능 여부, A[10] = '+', A[11] = '-' 의 가능 여부
vector<bool> P;
vector<int> A;

int AtoNum() {
    int ret = 100;
    for (int i=0; i<A.size(); ++i) {
        int a = A[i];
        if (a==10) ret++;
        else if (a==11) if (ret>0) ret--;
        else {
            if (i>0 && A[i-1]<10) {
                ret *= 10;
                ret += a;
            } else {
                ret = a;
            }
        }
    }
    return ret;
}

// A에 경우의 수 (순열) 기록
int solve() {
    if (AtoNum() == n) return A.size();
    if (A.size() > to_string(n).length()) return 987654321;

    int ret = 987654321;
    for (int i=0; i<12; ++i) {
        if (P[i]) {
            A.push_back(i);
            ret = min(ret, solve());
            A.pop_back();
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    int m; cin >> m; P.resize(12);
    for (int i=0; i<12; ++i) P[i] = true;
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        P[x] = false;
    }
    cout << solve() << endl;
}