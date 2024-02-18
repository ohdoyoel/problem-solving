#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string numbers = "";
int cache[10001];

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
        if (n[0] < n[sz(n) - 1] && n[i - 1] + 1 != n[i]) return false;
        else if (n[0] > n[sz(n) - 1] && n[i - 1] - 1 != n[i]) return false;
    }
    return true;
}

bool isNumbersArithmSeq(string n) {
    for (int i = 2; i < sz(n); ++i) {
        if (n[i - 1] - n[i - 2] != n[i] - n[i - 1]) return false;
    }
    return true;
}

int level(string n) {
    if (allNumbersSame(n)) return 1;
    if (numbersBlink(n)) return 4;
    if (numbersIncOrDecByOne(n)) return 2;
    if (isNumbersArithmSeq(n)) return 5;
    return 10;
}

int minLevel(int start) {
    int &res = cache[start];
    if (res != 987654321) return res;

    if (3 <= sz(numbers) - start && sz(numbers) - start <= 5) return res = level(numbers.substr(start));
    // else if (end - start < 3) return res = 987654321;

    // res = 987654321;
    for (int s = 3; s <= 5; ++s) {
        res = min(res, level(numbers.substr(start, start + s)) + minLevel(start + s));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c;
    cin >> c;
    while (c--) {
        for (int i = 0; i < 10001; ++i)
            cache[i] = 987654321;
        cin >> numbers;
        cout << minLevel(0) << endl;
    }

    return 0;
}