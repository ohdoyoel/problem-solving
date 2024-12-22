#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A, B;

int solve() {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    int ret = 0;
    for (int i=0; i<A.size(); ++i) {
        if (i==A.size()-1) {
            ret += A[i];
            break;
        }
        int sum = A[i]+A[i+1];
        int mut = A[i]*A[i+1];
        if (mut > sum) {
            ret += mut;
            i++;
        } else ret += A[i];
    }
    for (int i=0; i<B.size(); ++i) {
        if (i==B.size()-1) {
            ret += B[i];
            break;
        }
        int sum = B[i]+B[i+1];
        int mut = B[i]*B[i+1];
        if (mut > sum) {
            ret += mut;
            i++;
        } else ret += B[i];
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
    cout << solve() << endl;
    
    return 0;
}