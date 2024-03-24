#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

list<int> A;
vector<int> shifted;

int main() {
    int c; cin >> c;
    while(c--) {
        A.clear();
        int n; cin >> n; shifted.resize(n);
        for (int i=1; i<=n; i++) {
            cin >> shifted[i-1];
            A.push_back(i);
        }
        int idx = n-1;
        for (auto it=A.end(); it!=A.begin(); it--) {
            auto src = next(it, -1 - shifted[idx]); idx--;
            A.insert(it, *src); A.erase(src);
        }
        for (int a : A) cout << a << " ";
        cout << endl;
    }
}