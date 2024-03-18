#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

vector<lld> height;

lld solveStack() {
    stack<lld> remain;
    height.push_back(0);
    lld ret = 0;
    for (int i=0; i<height.size(); i++) {
        while(!remain.empty() && height[remain.top()] >= height[i]) {
            int j = remain.top();
            remain.pop();
            int width;
            if (remain.empty()) width = i;
            else width = i - remain.top() - 1;
            ret = max(ret, width * height[j]);
        }
        remain.push(i);
    }
    return ret;
}

int main() {
    int n; cin >> n; height.resize(n);
    for (int i=0; i<n; i++) cin >> height[i];
    cout << solveStack() << endl;
}