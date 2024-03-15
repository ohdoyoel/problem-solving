#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

map<string, int> freq;

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        string title; cin >> title;
        freq[title]++;
    }
    string maxTitle;
    int maxFreq = 0;
    for (auto psi : freq) {
        if (psi.second > maxFreq) {
            maxFreq = psi.second;
            maxTitle = psi.first;
        }
    }
    cout << maxTitle << endl;
}