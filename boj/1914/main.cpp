#include<bits/stdc++.h>
#include <cstdint>
#define endl "\n"
#define sz(x) (long long int)(x).size()
using namespace std;
using pii = pair<int,int>;
// using lld = ;

// 큰 수는 string으로 처리해야 함
string powNMinusOne(int n) {
    string temp = to_string(pow(2, n));
    int idx = temp.find('.');
    temp = temp.substr(0, idx);
    temp[temp.length() - 1]--;
    return temp;
}

int n;

// 하노이탑에서 상단 k개를 current에서 target으로 옮긴다.
void move(int k, int current, int target) {
    if (k==1) {
        cout << current << " " << target << endl;
        return;
    }

    move(k-1, current, 6-(current+target));
    move(1, current, target);
    move(k-1, 6-(current+target), target);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
    cin >> n;
    
    cout << powNMinusOne(n) << endl;
    if (n <= 20) move(n, 1, 3);
}