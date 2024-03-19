#include<bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int,int>;

int height[1001];

int main() {
    memset(height, 0, sizeof(height));

    int n; cin >> n;
    int H=0, HIdx=-1;
    while(n--) {
        int l, h; cin >> l >> h;
        height[l] = h;
        if (h > H) {
            H = h;
            HIdx = l;
        }
    }

    stack<int> noAreaIdx;
    int area = 0;
    for (int i=0; i<=HIdx; i++) {
        if (height[i] == 0) continue;
        while (!noAreaIdx.empty() && height[noAreaIdx.top()] <= height[i]) {
            area += height[noAreaIdx.top()] * (i - noAreaIdx.top());
            noAreaIdx.pop();
        }
        if (noAreaIdx.empty() && i!=HIdx) noAreaIdx.push(i);
        else if (i==HIdx) area += H;
    }
    for (int i=1000; i>=HIdx; i--) {
        if (height[i] == 0) continue;
        while (!noAreaIdx.empty() && height[noAreaIdx.top()] <= height[i]) {
            area += height[noAreaIdx.top()] * (noAreaIdx.top() - i);
            noAreaIdx.pop();
        }
        if (noAreaIdx.empty() && i!=HIdx) noAreaIdx.push(i);
        else if (i==HIdx) area += H;
    }

    cout << area - 10 << endl;
}