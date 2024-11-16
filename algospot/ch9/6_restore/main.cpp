#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int k;
vector<string> substrings;

// 최대 겹치는 길이 찾기 (문자열 전체를 비교)
int findMaxOverlap(const string& a, const string& b) {
    int maxOverlap = 0;
    int lenA = a.length(), lenB = b.length();

    // a의 끝과 b의 시작에서 겹치는 부분 찾기
    for (int i = 0; i < lenA; i++) {
        int overlap = 0;
        for (int j = 0; i + j < lenA && j < lenB; j++) {
            if (a[i + j] == b[j]) {
                overlap++;
            } else {
                break;
            }
        }
        maxOverlap = max(maxOverlap, overlap);
    }

    return maxOverlap;
}

// 두 문자열을 최소 길이로 합치기
string combine(const string& a, const string& b) {
    int overlap1 = findMaxOverlap(a, b); // a의 일부와 b가 겹치는 경우
    int overlap2 = findMaxOverlap(b, a); // b의 일부와 a가 겹치는 경우

    if (overlap1 >= overlap2) {
        return a + b.substr(overlap1); // 겹치는 부분 제외하고 결합
    } else {
        return b + a.substr(overlap2);
    }
}

string word() {
    string ret = substrings[0];
    for (int i=1; i<k; ++i) ret = combine(ret, substrings[i]);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        cin >> k; substrings.resize(k);
        for (int i=0; i<k; ++i) cin >> substrings[i];
        sort(substrings.begin(), substrings.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        cout << word() << endl;
    }
}