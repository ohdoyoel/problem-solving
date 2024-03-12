#include<bits/stdc++.h>
#define endl "\n"
#define all(x) x.begin(), x.end()
using namespace std;

struct treeNode {
    vector<treeNode*> children;
};

struct circle {
    int x = -1;
    int y = -1;
    int r = -1;
};

int n;
vector<circle> circles;

int sqrd(int x) {
    return x*x;
}

int sqrdDist(int a, int b) {
    return sqrd(circles[a].x - circles[b].x) + sqrd(circles[a].y - circles[b].y);
}

bool isEnclosedTo(int child, int parent) {
    return circles[parent].r > circles[child].r && sqrd(circles[parent].r - circles[child].r) > sqrdDist(parent, child);
}

bool isChildOf(int child, int parent) {
    if (!isEnclosedTo(child, parent)) return false;
    for (int i = 0; i < n; ++i)
        if (i != child && i != parent && isEnclosedTo(child, i) && isEnclosedTo(i, parent)) return false;
    
    return true;
}

treeNode* getTree(int root) {
    treeNode* ret = new treeNode();
    for (int i = 0; i < n; ++i) if(isChildOf(i, root)) ret->children.push_back(getTree(i));
    return ret;
}

int longest;

int height(treeNode* root) {
    vector<int> heights;
    for (int i = 0; i < root->children.size(); ++i) heights.push_back(height(root->children[i]));

    if (heights.empty()) return 0;
    sort(all(heights));

    if (heights.size() >= 2) longest = max(longest, 2 + heights.back() + heights[heights.size()-2]);

    return heights.back() + 1;
}

int solve(treeNode* root) {
    int h = height(root);
    return max(longest, h);
}

int main() {
    int c; cin >> c;
    while(c--) {
        cin >> n; circles.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> circles[i].x;
            cin >> circles[i].y;
            cin >> circles[i].r;
        }

        longest = 0;
        treeNode* circleTree = getTree(0);
        cout << solve(circleTree) << endl;
    }
}

// 큰 성벽이 부모가 되고, 그 안의 성벽은 자식이 되도록 (계층 구조를 표현!)
// 자식 트리의 개수가 1 -> depth 구하기
// 1 이상 -> 큰 depth 두개의 합