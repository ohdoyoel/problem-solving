#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> fences;

struct fenceAreaType {
    int area;
    int height;
    int width;
    pii range;
}

fenceAreaType maxFenceArea(pii range) {
    int width = range.second - range.first;
    if (width == 1) return {fences[range.first], fences[range.first], width, range};

    int midIdx = range.first + w / 2;
    fenceAreaType leftMaxFenceArea = maxFenceArea(make_pair(range.first, midIdx));
    fenceAreaType rightMaxFenceArea = maxFenceArea(make_pair(midIdx + 1, range.second));

    if (leftMaxFenceArea.range.second == rightMaxFenceArea.range.first) {
        int mergedArea = min(leftMaxFenceArea.height, rightMaxFenceArea.height) * (leftMaxFenceArea.width + rightMaxFenceArea.width);
        int leftArea = leftMaxFenceArea.area;
        int rightArea = rightMaxFenceArea.area;
        int maxArea = 
    }
}

int maxFenceArea() {
    return maxFenceArea(make_pair(0, len(fences)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while(c--){
        int n;
        cin >> n;
        fences.resize(n);
        for (int i = 0; i < n; ++i) cin >> fences[i];

        cout << maxFenceArea() << endl;
    }

    return 0;
}