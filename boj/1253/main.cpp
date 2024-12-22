#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;

int solve() {
    sort(A.begin(), A.end());
    int ret = 0;
    for (int i=0; i<n; ++i) {
        int start = 0;
        int end = n-1;
        while (start < end) {
            if (start==i) start++;
            else if (end==i) end--;
            else {
                int sum = A[start]+A[end];
                if (sum<A[i]) start++;
                else if (sum>A[i]) end--;
                else {
                    ret++;
                    break;
                }
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    cout << solve() << endl;

    return 0;
}