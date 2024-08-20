#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;

int maxArea(int b, int e) {
    if (e-b==1) return A[b];

    int m = (b+e) / 2;
    int leftArea = maxArea(b, m);
    int rightArea = maxArea(m, e);

    int leftEnd = m; int rightEnd = m+1;
    int pivot = A[leftEnd];
    int midArea = pivot;
    while(b <= leftEnd && rightEnd <= e) {
        pivot = min({A[leftEnd], pivot, A[rightEnd]});
        if (b <= leftEnd && A[leftEnd-1] >= pivot) leftEnd--;
        else if (rightEnd <= e && pivot <= A[rightEnd+1]) rightEnd++;
        midArea = max(pivot*(rightEnd-leftEnd), midArea);
    }

    return max({leftArea, midArea, rightArea});
}

int main() {
    int c; cin >> c;
    while (c--) {
        cin >> n; A.resize(n);
        for (int i=0; i<n; i++) cin >> A[i];
        cout << maxArea(0, n) << endl;
    }
}