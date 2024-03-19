#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        set<int> heap;
        map<int,int> freq;
        int n; cin >> n;
        while(n--) {
            char cmd; cin >> cmd;
            if (cmd == 'I') {
                int x; cin >> x;
                heap.insert(x);
                freq[x]++;
            } else if (cmd == 'D') {
                int x; cin >> x;
                if (heap.empty()) continue;
                if (x == 1) {
                    freq[*next(heap.end(), -1)]--;
                    if (freq[*next(heap.end(), -1)] == 0) heap.erase(next(heap.end(), -1));
                }
                else if (x == -1) {
                    freq[*heap.begin()]--;
                    if (freq[*heap.begin()] == 0) heap.erase(heap.begin());
                }
            }
        }
        if (heap.empty()) cout << "EMPTY" << endl;
        else cout << *next(heap.end(), -1) << " " << *heap.begin() << endl;
    }
}