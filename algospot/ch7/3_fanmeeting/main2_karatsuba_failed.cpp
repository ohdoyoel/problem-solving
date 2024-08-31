#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

/* A와 B의 곱한 결과 벡터로*/
vector<int> multiply(vector<int>& A, vector<int>& B) {
    vector<int> res(A.size() + B.size());
    for (int a=0; a<A.size(); a++) {
        for (int b=0; b<B.size(); b++) {
            int m = A[a]*B[b];
            res[a+b] += m % 10;
            res[a+b+1] += m / 10;
        }
    }
    // for (int r : res) cout << r << ' ';
    // cout << endl;
    return res;
}

/* return A+B*/
vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> res = B;
    for (int i=0; i<A.size(); i++) {
        res[i] += (A[i]+res[i]) % 10;
        res[i+1] += (A[i]+res[i]) / 10;
    }
    return res;
}

/* return A-B*/
vector<int> substract(vector<int>& A, vector<int>& B) {
    vector<int> res = B;
    for (int i=0; i<A.size(); i++) {
        int m = res[i]-A[i];
        if (m >= 0) res[i] = m;
        else {
            res[i+1]-=1;
            res[i] = 10+m;
        }
    }
    return res;
}

vector<int> shift(vector<int>& A, int shift){
    vector<int> res(A.size()+shift);
    for(int i=0; i<A.size(); i++) res[i+shift] = A[i];
    return res;
}

vector<int> karatsuba(vector<int>& A, vector<int>& B) {
    if (A.size() == 0 && B.size() == 0) return vector<int>();
    if (B.size() <= 50) return multiply(A, B);

    int half = B.size() / 2;
    vector<int> a0(A.begin(), A.begin() + min<int>(half, A.size()));
    vector<int> a1(A.begin() + min<int>(half, A.size()), A.end());
    vector<int> b0(B.begin(), B.begin() + half);
    vector<int> b1(B.begin() + half, B.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z1_0 = add(a0, a1);
    vector<int> z1_1 = add(b0, b1);
    vector<int> z1 = karatsuba(z1_0, z1_1);
    z1 = substract(z1, z0);
    z1 = substract(z1, z2);
    
    vector<int> z2_shift = shift(z2, half*2);
    vector<int> z1_shift = shift(z1, half);
    z0 = add(z0, z1_shift);
    z0 = add(z0, z2_shift);
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