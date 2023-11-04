// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

uint cnt;
vector<pii> friendPair;

int findIndexOfPairInListOfPair(pii pair, vector<pii>& pairs) {
    for (uint i = 0; i < sz(pairs); ++i) {
        if (pair.first == pairs[i].first && pair.second == pairs[i].second) return i;
    }
    return -1;
}

int tailIndexPlusOneIncludingEmpty(vector<pii>& v) {
    if (sz(v) == 0) return 0;
    pii tail = v.back();
    return findIndexOfPairInListOfPair(tail, friendPair) + 1;
}

bool isElementInPairNotExistInListOfPair(pii pair, vector<pii>& pairs) {
    for (uint i = 0; i < sz(pairs); ++i) {
        if (pair.first == pairs[i].first || pair.first == pairs[i].second
            || pair.second == pairs[i].first || pair.second == pairs[i].second) return false;
    }
    return true;
}

void pickAndUpdateCnt(vector<pii>& pickedFriendPair, int numOfRestFriendPair) {
    // cout << "numOfRestFriendPair " << numOfRestFriendPair << endl;
    if (numOfRestFriendPair == 0) { cnt++;
    // cout << "cnt " << cnt << endl;
    return; }

    int startIndex = tailIndexPlusOneIncludingEmpty(pickedFriendPair);
    // cout << "startIndex " << startIndex << endl;
    
    for (int i = startIndex; i < sz(friendPair); ++i) {
        // cout << "{" << "i " << i << " among " << sz(friendPair) << endl;
        if (isElementInPairNotExistInListOfPair(friendPair[i], pickedFriendPair)) {
            pickedFriendPair.push_back(friendPair[i]);
            pickAndUpdateCnt(pickedFriendPair, numOfRestFriendPair - 1);
            pickedFriendPair.pop_back();
        }
        // cout << "i " << i << " among " << sz(friendPair) << "}" << endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        
    uint c;
    cin >> c;
    // cout << c << endl;

    for (uint i = 0; i < c; ++i) {
        uint n, m;
        cin >> n >> m;
        // cout << n << " " << m << endl;
        friendPair.resize(m);
        for (uint j = 0; j < m; ++j) {
            int a, b;
            cin >> a >> b;
            // cout << a << " " << b << endl;
            friendPair[j] = make_pair(a, b);
        }

        vector<pii> pickedFriendPair;
        cnt = 0;
        pickAndUpdateCnt(pickedFriendPair, n / 2);
        cout << cnt << endl;
    }

    return 0;
}