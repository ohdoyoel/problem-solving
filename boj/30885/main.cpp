#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long int;
using pli = pair<lld,int>;

list<pli> A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        lld a; cin >> a;
        A.push_back(make_pair(a, i));
    }

    while(A.size() != 1) {
        for (auto it=A.begin(); it!=A.end(); ++it) {
            if (it!=A.begin() && next(it, -1)->first <= it->first
                && it!=next(A.end(), -1) && it->first >= next(it, 1)->first){
                it->first += next(it, -1)->first;
                it->first += next(it, 1)->first;
                A.erase(next(it, -1));
                A.erase(next(it, 1));
            } else if (it!=A.begin() && next(it, -1)->first <= it->first){
                it->first += next(it, -1)->first;
                A.erase(next(it, -1));
            } else if (it!=next(A.end(), -1) && it->first >= next(it, 1)->first) {
                it->first += next(it, 1)->first;
                A.erase(next(it, 1));
            }
            // for (pii a : A) cout << a.first << " ";
            // cout << endl;
        }
    }

    cout << A.front().first << endl;
    cout << A.front().second << endl;
}