#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

stack<short> wait;
vector<short> waits;

int main() {
    short n; cin >> n; waits.resize(n);
    for (int i=0; i<n; i++) cin >> waits[i];
    
    int i = 1;
    
    for(int w : waits) {
        if (w == i) {
            i++;
            continue;
        }
        while (!wait.empty() && wait.top() == i) {
            wait.pop();
            i++;
        }
        wait.push(w);
    }
    
    while (!wait.empty() && wait.top() == i) {
        wait.pop();
        i++;
    }

    if (wait.empty()) cout << "Nice" << endl;
    else cout << "Sad" << endl;
}