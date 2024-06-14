#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

vector<int> in;
vector<int> post;
vector<int> pre;

void buildPre(int startIn, int endIn, int startPost, int endPost) {
    if (startIn==endIn) return;

    int root = post[endPost-1];

    int startInLeft=startIn; int endInLeft=startIn;
    int startInRight=startIn; int endInRight=endIn;
    for (int rootIdx=startIn; rootIdx<endIn; rootIdx++) {
        if (in[rootIdx]==root) {
            endInLeft = rootIdx;
            startInRight = rootIdx+1;
            break;
        }
    }

    int sizeLeft=endInLeft-startInLeft; int sizeRight=endInRight-startInRight;
    int startPostLeft=startPost; int endPostLeft=startPostLeft+sizeLeft;
    int startPostRight=endPostLeft; int endPostRight=startPostRight+sizeRight;

    pre.push_back(root);
    buildPre(startInLeft, endInLeft, startPostLeft, endPostLeft);
    buildPre(startInRight, endInRight, startPostRight, endPostRight);
}

int main() {
    int n; cin >> n;
    in.resize(n); post.resize(n);
    for (int i=0; i<n; i++) cin >> in[i];
    for (int i=0; i<n; i++) cin >> post[i];

    buildPre(0, n, 0, n);
    for (int p : pre) cout << p << " ";
}