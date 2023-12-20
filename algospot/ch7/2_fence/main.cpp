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
};

fenceAreaType maxFenceArea(pii range) {
    cout << "in range of " << range.first << " " << range.second << endl;
    int width = range.second - range.first;
    if (width == 1) return {fences[range.first], fences[range.first], width, range};

    int midIdx = range.first + width / 2; // 제일 작은 놈의 idx 뽑기
    fenceAreaType leftMaxFenceArea = maxFenceArea(make_pair(range.first, midIdx));
    cout << "left Max Is " << leftMaxFenceArea.area << " " << leftMaxFenceArea.height << " " << leftMaxFenceArea.width << " " << leftMaxFenceArea.range.first << "," << leftMaxFenceArea.range.second << endl;
    fenceAreaType rightMaxFenceArea = maxFenceArea(make_pair(midIdx, range.second));
    cout << "right Max Is " << rightMaxFenceArea.area << " " << rightMaxFenceArea.height << " " << rightMaxFenceArea.width << " " << rightMaxFenceArea.range.first << "," << rightMaxFenceArea.range.second << endl;


    if (leftMaxFenceArea.range.second == rightMaxFenceArea.range.first) {
        int mergedAreaValue = min(leftMaxFenceArea.height, rightMaxFenceArea.height) * (leftMaxFenceArea.width + rightMaxFenceArea.width);
        int leftAreaValue = leftMaxFenceArea.area;
        int rightAreaValue = rightMaxFenceArea.area;
        int maxAreaValue = max({mergedAreaValue, leftAreaValue, rightAreaValue});
        
        if (maxAreaValue == mergedAreaValue) {
            return {
              maxAreaValue,
              min(leftMaxFenceArea.height, rightMaxFenceArea.height),
              leftMaxFenceArea.width + rightMaxFenceArea.width,
              make_pair(leftMaxFenceArea.range.first, rightMaxFenceArea.range.second)
            };
        } else if (maxAreaValue == leftAreaValue) {
            return leftMaxFenceArea;
        } else if (maxAreaValue == rightAreaValue) {
            return rightMaxFenceArea;
        }
        
    } else {
        if (leftMaxFenceArea.area > rightMaxFenceArea.area) {
            return leftMaxFenceArea;
        } else {
            return rightMaxFenceArea;
        }
    }
}

int maxFenceArea() {
    return maxFenceArea(make_pair(0, sz(fences))).area;
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