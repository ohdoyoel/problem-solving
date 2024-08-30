#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;

int maxArea(int b, int e) {
    if (b==e) return A[b];

    int m = (b+e) / 2;
    int leftArea = maxArea(b, m);
    int rightArea = maxArea(m+1, e);
    int ret = max(leftArea, rightArea);

    int leftEnd = m; int rightEnd = m+1;
    int pivot = min(A[leftEnd], A[rightEnd]);
    while (b <= leftEnd-1 && A[leftEnd-1] >= pivot) leftEnd--;
    while (rightEnd+1 <= e && pivot <= A[rightEnd+1]) rightEnd++;
    int midArea = pivot*(rightEnd-leftEnd+1);
    
    while(b <= leftEnd-1 || rightEnd+1 <= e) {
        if(A[leftEnd-1] < pivot && pivot > A[rightEnd+1]) pivot = max(A[leftEnd-1], A[rightEnd+1]);
        else if (A[leftEnd-1] < pivot) pivot = A[leftEnd-1];
        else if (A[rightEnd+1] < pivot) pivot = A[rightEnd+1];
        while (b <= leftEnd-1 && A[leftEnd-1] >= pivot) leftEnd--;
        while (rightEnd+1 <= e && pivot <= A[rightEnd+1]) rightEnd++;
        midArea = max(pivot*(rightEnd-leftEnd+1), midArea);
    }

    return max(ret, midArea);
}

int main() {
    int c; cin >> c;
    while (c--) {
        cin >> n; A.resize(n);
        for (int i=0; i<n; i++) cin >> A[i];
        cout << maxArea(0, n-1) << endl;
    }
}