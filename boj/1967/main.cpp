#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int,int>;

struct compFirst {
    bool operator()(pii a, pii b) { return a.first > b.first; };
} comp;

// childEdges[i] = i에서 자녀로 연결된 간선들
vector<vector<pii>> childEdges;

struct node {
    vector<pair<node*,int>> children;
};

using pni = pair<node*,int>;

node* getTree(int root) {
    node* ret = new node();
    for (pii childCost : childEdges[root]) {
        ret->children.push_back(make_pair(getTree(childCost.first), childCost.second));
    }
    return ret;
}

int height(node* root) {
    int ret = 0;
    for (pni childCost : root->children) ret = max(ret, childCost.second+height(childCost.first));
    cout << ret << endl;
    return ret;
}

int radiusCand(node* root) {
    if (root->children.size() == 0) return 0;
    if (root->children.size() == 1) return root->children[0].second+height(root->children[0].first);
    vector<pii> costHeights;
    for (pni childCost : root->children) {
        costHeights.push_back(make_pair(childCost.second, height(childCost.first)));
    }
    sort(all(costHeights), comp);
    return costHeights[0].second + costHeights[0].first + costHeights[1].first + costHeights[1].second;
}

int radius = 0;
void setRadius(node* root) {
    for (pni childCost : root->children) {
        radius = max(radius, radiusCand(childCost.first));
        setRadius(childCost.first);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n; childEdges.resize(n+1);
    int t = n-1;
    while(t--) {
        int s, d, c; cin >> s >> d >> c;
        childEdges[s].push_back(make_pair(d, c));
    }

    node* tree = getTree(1);
    setRadius(tree);
    
    cout << radius << endl;
}