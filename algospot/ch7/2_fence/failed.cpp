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

int minIdxOfFences (pii range) {
    int minIdx = range.first;
    for (int i = range.first; i < range.second; ++i) {
        if (fences[i] < fences[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

fenceAreaType maxFenceArea(pii range) {
    cout << "in range of " << range.first << " " << range.second << endl;
    int width = range.second - range.first;
    // if (width == 0) return {0, 0, width, range};
    if (width == 1) return {fences[range.first], fences[range.first], width, range};

    int midIdx = minIdxOfFences(range);
    // int midIdx = range.first + width / 2;
    if (midIdx == range.first) midIdx++;
    
    // cout << "{" << endl;
    // cout << "left" << endl;
    fenceAreaType leftMaxFenceArea = maxFenceArea(make_pair(range.first, midIdx));
    // cout << "left Max Is " << leftMaxFenceArea.area << " " << leftMaxFenceArea.height << " " << leftMaxFenceArea.width << " " << leftMaxFenceArea.range.first << "," << leftMaxFenceArea.range.second << endl;
    // cout << "right" << endl;
    fenceAreaType rightMaxFenceArea = maxFenceArea(make_pair(midIdx, range.second));
    // cout << "right Max Is " << rightMaxFenceArea.area << " " << rightMaxFenceArea.height << " " << rightMaxFenceArea.width << " " << rightMaxFenceArea.range.first << "," << rightMaxFenceArea.range.second << endl;
    // cout << "}" << endl;

    fenceAreaType maxArea = {0, 0, width, range};
    
    if (leftMaxFenceArea.range.second == rightMaxFenceArea.range.first) {
        int mergedAreaValue = min(leftMaxFenceArea.height, rightMaxFenceArea.height) * (leftMaxFenceArea.width + rightMaxFenceArea.width);
        int leftAreaValue = leftMaxFenceArea.area;
        int rightAreaValue = rightMaxFenceArea.area;
        int maxAreaValue = max({mergedAreaValue, leftAreaValue, rightAreaValue});
        
        // 만약 넓이가 같다면, 어떤 놈을 반환하느냐에 따라 다음 값이 달라짐
        // 그럼 모두 반환한다면? 그니까 아래 for문에서 각각 변수를 또 만들고 함수 다시 호출하고 마지막에 비교해서 값하나만 넘기는 거임
        
        if (maxAreaValue == mergedAreaValue) {
            maxArea = {
              maxAreaValue,
              min(leftMaxFenceArea.height, rightMaxFenceArea.height),
              leftMaxFenceArea.width + rightMaxFenceArea.width,
              make_pair(leftMaxFenceArea.range.first, rightMaxFenceArea.range.second)
            };
        } else if (maxAreaValue == leftAreaValue) {
            maxArea = leftMaxFenceArea;
        } else if (maxAreaValue == rightAreaValue) {
            maxArea = rightMaxFenceArea;
        }
        
    } else {
        if (leftMaxFenceArea.area > rightMaxFenceArea.area) {
            maxArea = leftMaxFenceArea;
        } else {
            maxArea = rightMaxFenceArea;
        }
    }
    
    cout << "maxArea is " << maxArea.area << " " << maxArea.height << " " << maxArea.width << " " << maxArea.range.first << "," << maxArea.range.second << " in " << range.first << "," << range.second << endl;
    
    return maxArea;
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