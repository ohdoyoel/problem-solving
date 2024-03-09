#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int k;
vector<int> survivors;

// f이 죽고, 다음 k번째 있는 사람이 죽음
void lastTwo(int f) {
    if (survivors.size() == 1) {
        cout << survivors[0] << ">";
        return ;
    }

    f %= survivors.size();
    cout << survivors[f] << ", ";
    survivors.erase(survivors.begin() + f);
    lastTwo(f + k - 1);
}

int main() {
    int n; cin >> n >> k;
    survivors.resize(n);
    for (int i = 0; i < n; ++i) survivors[i] = i+1;
    cout << "<";
    lastTwo(k - 1);
}