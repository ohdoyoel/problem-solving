#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

vector<int> A;

void showA(int start, int end) {
    if (start==end) return;
    
    int mid = (start+end-1) / 2;
    cout << A[mid] << " ";
    showA(start, mid);
    showA(mid+1, end);
}

int main() {
    int k; cin >> k; A.resize(pow(2, k)-1);
    for (int i=0; i<sz(A); i++) cin >> A[i];
    showA(0, sz(A));
}