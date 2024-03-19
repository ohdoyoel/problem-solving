#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long int;

stack<int> s;
vector<int> height;
vector<lld> result;

int main() {
    int n; cin >> n; height.resize(n); result.resize(n+1);
    for (int i=0; i<n; i++) cin >> height[i];
    height.push_back(1000000001);

    for (int i=0; i<=n; i++) {
        while(!s.empty() && height[s.top()] < height[i]) {
            lld res = 0;
            for (int j=s.top()+1; j<i; j++) {
                if (height[s.top()] > height[j]) res++;
            }
            result[s.top()] = res;
            s.pop();
        }
        s.push(i);
    }
    
    
    // result[s.top()] = 0;
    // s.pop();
    // for(; !s.empty(); s.pop()) {
    //     if (height[s.top()] > height[s.top()+1]) result[s.top()] = result[s.top()+1] + 1;
    //     else if (height[s.top()] == height[s.top()+1]) result[s.top()] = result[s.top()+1];
    // }
    

    // for (int r : result) cout << r << " ";
    
    lld ret = 0;
    for (lld r : result) ret += r;
    cout << ret << endl;
}