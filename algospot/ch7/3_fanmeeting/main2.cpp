#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> A, B;

/* A와 B의 곱한 결과 벡터로*/
vector<int> multiply() {
    vector<int> res(A.size() + B.size());
    for (int a=0; a<A.size(); a++) {
        for (int b=0; b<B.size(); b++) {
            int m = A[a]*B[b];
            res[a+b] += m % 10;
            res[a+b+1] += m / 10;
        }
    }
    return res;
}

int main() {
    int c; cin >> c;
    while (c--) {
        string strA, strB; cin >> strA >> strB;
        A.clear(); B.clear();
        for (int i=strA.size()-1; i>=0; i--) A.push_back(strA[i] == 'M');
        for (int i=0; i<strB.size(); i++) B.push_back(strB[i] == 'M');

        vector<int> res = multiply();
        int zeroCnt = 0;
        for (int i=0; i<strA.size(); i++) if (res[i] == 0) zeroCnt++;
        cout << zeroCnt << endl;
    }
}