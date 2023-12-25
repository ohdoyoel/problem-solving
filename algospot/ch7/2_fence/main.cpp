#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<int> fences;

int maxFenceArea(pii range) {
    int width = range.second - range.first;
    if (width == 0) return 0;
    else if (width == 1) return fences[range.first];

    int midIdx = range.first + width / 2;

    int leftMaxFenceArea = maxFenceArea(make_pair(range.first, midIdx));
    int rightMaxFenceArea = maxFenceArea(make_pair(midIdx, range.second));
    // int leftMaxFenceArea = 0;
    // int rightMaxFenceArea = 0;

    int midMaxFenceHeight = min(fences[midIdx - 1], fences[midIdx]);
    int midMaxFenceArea = 2 * midMaxFenceHeight;
    
    int leftEnd = midIdx - 1;
    int rightEnd = midIdx;

    int leftEndFenceHeight, rightEndFenceHeight, cand, w;

    while ((range.first < leftEnd) || (rightEnd < range.second - 1)) {
      cout << range.first << " " << leftEnd << " " << rightEnd <<  " " << range.second << endl;
        if (range.first < leftEnd) leftEnd--;
        if (rightEnd < range.second - 1) rightEnd++;

        leftEndFenceHeight = min(fences[leftEnd], midMaxFenceHeight);
        rightEndFenceHeight = min(fences[rightEnd], midMaxFenceHeight);
        if (leftEndFenceHeight > rightEndFenceHeight) {
            rightEnd--;
            w = rightEnd - leftEnd + 1;
            cand = leftEndFenceHeight * w;
        } else {
            leftEnd++;
            w = rightEnd - leftEnd + 1;
            cand = rightEndFenceHeight * w;
        }
        
        midMaxFenceArea = max(midMaxFenceArea, cand);
    } // 요기 코드를 이상하게 짬
    
    return max({leftMaxFenceArea, rightMaxFenceArea, midMaxFenceArea});
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
        
        cout << maxFenceArea(make_pair(0, n)) << endl;
    }

    return 0;
}