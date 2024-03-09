#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> survivors;

// f이 죽고, 다음 k번째 있는 사람이 죽음
void lastTwo(int f, int k) {
    if (survivors.size() == 2) return ;

    f %= survivors.size();
    survivors.erase(survivors.begin() + f);
    lastTwo(f + k - 1, k);
}

int main() {
    int c; cin >> c;
    while(c--) {
        int n, k; cin >> n >> k;
        survivors.resize(n);
        for (int i = 0; i < n; ++i) survivors[i] = i+1;
        lastTwo(0, k);
        cout << survivors[0] << " " << survivors[1] << endl;
    }
}