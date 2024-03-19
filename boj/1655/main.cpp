#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

priority_queue<int, vector<int>, less<int>> maxH;
priority_queue<int, vector<int>, greater<int>> minH;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        if (maxH.size() == minH.size()) maxH.push(x);
        else minH.push(x);
        if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top()) {
            int a = maxH.top(), b = minH.top();
            maxH.pop(); maxH.push(b);
            minH.pop(); minH.push(a);
        }
        cout << maxH.top() << endl;
    }
}