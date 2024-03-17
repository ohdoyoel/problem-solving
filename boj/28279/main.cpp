#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while(n--) {
        int in; cin >> in;
        switch (in) {
            case 1: {
                int x; cin >> x;
                dq.push_front(x);
                break;
            }
            case 2: {
                int x; cin >> x;
                dq.push_back(x);
                break;
            }
            case 3: {
                if (dq.empty()) {
                    cout << -1 << endl;
                    break;
                }
                cout << dq.front() << endl;
                dq.pop_front();
                break;
            }
            case 4: {
                if (dq.empty()) {
                    cout << -1 << endl;
                    break;
                }
                cout << dq.back() << endl;
                dq.pop_back();
                break;
            }
            case 5: {
                cout << dq.size() << endl;
                break;
            }
            case 6: {
                cout << dq.empty() << endl;
                break;
            }
            case 7: {
                if (dq.empty()) {
                    cout << -1 << endl;
                    break;
                }
                cout << dq.front() << endl;
                break;
            }
            case 8: {
                if (dq.empty()) {
                    cout << -1 << endl;
                    break;
                }
                cout << dq.back() << endl;
                break;
            }
        }
    }
}