#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[10001];
vector<int> numbers;

bool isAllSame(int i, int j) {
    int n = numbers[i];
    for (int k=i; k<j; k++) if (n != numbers[k]) return false;
    return true;
}

bool isMonoIncOrDec(int i, int j) {
    bool inc = numbers[i] < numbers[i+1];
    if (inc) {
        for (int k=i; k<j; k++) if (numbers[i] + (k-i) != numbers[k]) return false;
        return true;
    } else {
        for (int k=i; k<j; k++) if (numbers[i] - (k-i) != numbers[k]) return false;
        return true;
    }
}

bool isBlinking(int i, int j) {
    int a = numbers[i], b = numbers[i+1];
    for (int k=i; k<j; k++) {
        if ((k-i) % 2) {
            if (b != numbers[k]) return false;
        } else {
            if (a != numbers[k]) return false;
        }
    }
    return true;
}

bool isArthSeq(int i, int j) {
    int d = numbers[i+1] - numbers[i];
    for (int k=i; k<j-1;k++) if (numbers[k+1] - numbers[k] != d) return false;
    return true;
}

// numbers[i ... j-1]의 난이도
int level(int i, int j) {
    if (isAllSame(i, j)) return 1;
    else if (isMonoIncOrDec(i, j)) return 2;
    else if (isBlinking(i, j)) return 4;
    else if (isArthSeq(i, j)) return 5;
    else return 10;
}

// i를 포함한 이후의 numbers에서 쪼개고 난 후 난이도들의 최소 합
int minLevel(int i) {
    if (i == numbers.size()) return 0;
  
    int& ret = cache[i];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int skip=3; skip<=5 && i+skip <= numbers.size(); skip++) {
        // cout << "조각:" << i << " " << skip << " " << level(i, i+skip) << endl;
        // cout << "나머지:" << minLevel(i + skip) << endl;
        ret = min(ret, level(i, i+skip) + minLevel(i + skip));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c; cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        string str; cin >> str; numbers.clear();
        for (char s : str) numbers.push_back(s -'0');
        cout << minLevel(0) << endl;;
    }

    return 0;
}
