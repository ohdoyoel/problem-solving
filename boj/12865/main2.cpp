#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][100001];
int n;
vector<int> weight, val;

// item부터 관찰해서 capcity 이내의 가장 큰 가치
int value(int item, int capacity) {
    if (item == n) return 0;

    int& ret = cache[item][capacity];
    if (ret!=-1) return ret;

    ret = 0;
    ret = max(ret, value(capacity, item+1));
    if (weight[item] <= capacity) ret = max(ret, value(capacity - weight[item], item+1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int k; cin >> n >> k; weight.resize(n); val.resize(n);
    for (int i=0; i<n; i++) cin >> weight[i] >> val[i];
    cout << value(0, k) << endl;
}