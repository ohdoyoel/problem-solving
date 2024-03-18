#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

stack<int> s;
vector<int> number;
vector<int> result;

int main() {
    int n, k; cin >> n >> k; number.resize(n);
    string num; cin >> num;
    for (int i=0; i<n; i++) number[i] = num[i] - '0';

    int removeCnt = k;
    for (int i=0; i<n; i++) {
        while(!s.empty() && s.top() < number[i] && removeCnt > 0) {
            s.pop();
            removeCnt--;
        }
        s.push(number[i]);
    }

    for (; !s.empty(); s.pop()) result.push_back(s.top());

    reverse(all(result));
    for (int r : result) cout << r << endl;
}