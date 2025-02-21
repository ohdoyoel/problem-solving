#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A, B;

int solve() {
    int ret = 0;
    for (int a=0; a<A.size(); ++a) {
        if (a==A.size()-1) {
            ret += A[a];
            break;
        }
        int sum = A[a] + A[a+1];
        int mul = A[a] * A[a+1];
        if (mul >= sum) {
            ret += mul;
            ++a;
        } else ret += A[a];
    }
    for (int b=0; b<B.size(); ++b) {
        if (b==B.size()-1) {
            ret += B[b];
            break;
        }
        int sum = B[b] + B[b+1];
        int mul = B[b] * B[b+1];
        if (mul >= sum) {
            ret += mul;
            ++b;
        } else ret += B[b];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (x>0) A.push_back(x);
        else B.push_back(x);
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    cout << solve() << endl;
}