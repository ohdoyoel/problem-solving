#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

struct circle {
    int x, y, r;
    int parent = -1;
    vector<int> children;
};

int n;
vector<circle> CIRCLES;

bool isChildOf(int a, int b) {
    if (!isEnclosedTo(a, b)) return false;
    for (int i=0; i<n; ++i) {
        if 
    }
}

void buildTree() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (isChildOf(j, i)) {
                CIRCLES[j].parent = i;
                CIRCLES[i].children.push_back(j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        cin >> n; CIRCLES.resize(n);
        for (int i=0; i<n; ++i) cin >> CIRCLES[i].x >> CIRCLES[i].y >> CIRCLES[i].r;
        buildTree();
    }
}