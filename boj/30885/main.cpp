#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int,int>;

list<pii> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        int a; cin >> a;
        A.push_back(make_pair(a, i));
    }

    while(A.size() != 1) {
        for (auto it=A.begin(); it!=A.end(); ++it) {
            if (it!=A.begin() && next(it, -1)->first <= it->first){
                it->first += next(it, -1)->first;
                A.erase(next(it, -1));
            }
            if (it!=next(A.end(), -1) && it->first >= next(it, 1)->first) {
                it->first += next(it, 1)->first;
                A.erase(next(it, 1));
            }
        }
    }

    cout << A.front().first << endl;
    cout << A.front().second << endl;
}