#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void normalize(vector<int>& A) {
    for (int i=0; i<A.size(); i++) {
        if (A[i] > 9) {
            A[i] %= 10;
            if (i == A.size()-1) A.push_back(1);
            else A[i+1] += 1;
        }
    }
}

/* A와 B의 곱한 결과 벡터로*/
vector<int> multiply(vector<int>& A, vector<int>& B) {
    vector<int> res(A.size() + B.size());
    for (int a=0; a<A.size(); a++) {
        for (int b=0; b<B.size(); b++) {
            int m = A[a]*B[b];
            res[a+b] += m % 10;
        }
    }
    // for (int r : res) cout << r << ' ';
    // cout << endl;
    normalize(res);
    return res;
}

/* A += B*(10^shift)*/
void addTo(vector<int>& A, vector<int>& B, int shift) {
    for (int i=0; i<B.size(); i++) A[shift+i] += B[i];
    normalize(A);
}

/* A -= B */
void substractFrom(vector<int>& A, vector<int>& B) {
    for (int i=0; i<B.size(); i++) {
        int s = A[i] - B[i];
        if (s >= 0) A[i] += s;
        else {
            A[i+1] -= 1;
            A[i] = 10 + s;
        }
    }
}

vector<int> karatsuba(vector<int>& A, vector<int>& B) {
    if (A.size() > B.size()) return karatsuba(B, A);
    if (A.size() == 0 || B.size() == 0) return vector<int>();
    if (B.size() <= 50) return multiply(A, B);

    int half = B.size() / 2;
    vector<int> a0(A.begin(), A.begin() + min<int>(half, A.size()));
    vector<int> a1(A.begin() + min<int>(half, A.size()), A.end());
    vector<int> b0(B.begin(), B.begin() + half);
    vector<int> b1(B.begin() + half, B.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    substractFrom(z1, z0); substractFrom(z1, z2);
    
    addTo(z0, z1, half); addTo(z0, z2, half*2);
    return z0;
}


int main() {
    int c; cin >> c;
    while (c--) {
        string strA, strB; cin >> strA >> strB;
        vector<int> A; vector<int> B;
        for (int i=strA.size()-1; i>=0; i--) A.push_back(strA[i] == 'M');
        for (int i=0; i<strB.size(); i++) B.push_back(strB[i] == 'M');

        vector<int> res = karatsuba(A, B);
        int zeroCnt = 0;
        for (int i=A.size()-1; i<B.size(); i++) if (res[i] == 0) zeroCnt++;
        cout << zeroCnt << endl;
    }
}