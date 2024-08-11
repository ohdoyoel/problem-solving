#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> A;
int t, k, res;

void merge(int p, int q, int r) {
    int i = p;
    int j = q+1;
    vector<int> tmp;
    while (i<=q && j<=r) {
        if (A[i] < A[j]) tmp.push_back(A[i++]);
        else tmp.push_back(A[j++]);
    }
    while(i<=q) tmp.push_back(A[i++]);
    while(j<=r) tmp.push_back(A[j++]);

    for (int l=p; l<=r; l++) {
        t++;
        if (t == k) res = tmp[l-p];
        A[l] = tmp[l-p];
    }
}

void mergeSort(int p, int r) {
    if (p < r) {
        int q = (p+r) / 2;
        mergeSort(p, q);
        mergeSort(q+1, r);
        merge(p, q, r);
    }
}

void printA() {
    for (int a : A) {
        cout << a << ' ';
    }
    cout << endl;
}

int main() {
    int n; cin >> n >> k; A.resize(n);
    for (int i=0; i<n; i++) cin >> A[i];
    t = 0;
    res = 987654321;
    mergeSort(0, n-1);
    // printA();
    if (res == 987654321) cout << -1 << endl;
    else cout << res << endl;
}