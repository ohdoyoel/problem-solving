#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string numbers;
int cache[10000];

bool allNumbersSame(string n) {
    for (int i = 0; i < sz(n); ++i) {
        if (n[0] != n[i]) return false;
    }
    return true;
}

bool numbersBlink(string n) {
    for (int i = 0; i < sz(n); ++i) {
        if (2 * i < sz(n) && n[0] != n[2 * i]) return false;
        if (2 * i + 1 < sz(n) && n[1] != n[2 * i + 1]) return false;
    }
    return true;
}

bool numbersIncOrDecByOne(string n) {
    for (int i = 1; i < sz(n); ++i) {
        if (n[0] < n[sz(n) - 1] && 1 != n[i] - n[i - 1]) return false;
        else if (n[0] > n[sz(n) - 1] && -1 != n[i] - n[i - 1]) return false;
    }
    return true;
}

bool isNumbersArithmSeq(string n) {
    for (int i = 1; i < sz(n); ++i) {
        if (n[1] - n[0] != n[i] - n[i - 1]) return false;
    }
    return true;
}

int level(string n) {
    // if (allNumbersSame(n)) return 1;
    // if (numbersBlink(n)) return 4;
    // if (numbersIncOrDecByOne(n)) return 2;
    // if (isNumbersArithmSeq(n)) return 5;
    // return 10;
    
    if (n == string(sz(n), n[0])) return 1;
    
    bool progressive = true;
    for (int i = 1; i < sz(n); ++i)
        if (n[1] - n[0] != n[i] - n[i - 1]) progressive = false;
    if (progressive && abs(n[1] - n[0]) == 1) return 2;
    else if (progressive) return 5;
    
    bool alternave = true;
    for (int i = 0; i < sz(n); ++i)
        if (n[i] != n[i%2]) alternave = false;
    if (alternave) return 4;
    
    return 10;
}

int minLevel(int start) {
    if (start == sz(numbers)) return 0;
    
    int &res = cache[start];
    if (res != -1) return res;
    
    res = 987654321;
    for (int s = 3; s <= 5 && start + s <= sz(numbers); ++s) {
        res = min(res, level(numbers.substr(start, s)) + minLevel(start + s));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        cin >> numbers;
        cout << minLevel(0) << endl;
    }

    return 0;
}

// -1로 놓아도 상관 x
// level함수 만들기
// substr 내용 정리, 두번째 인자는 길이 (끝 인덱스가 아님)
