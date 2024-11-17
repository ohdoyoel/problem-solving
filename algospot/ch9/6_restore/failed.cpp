#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int k;
vector<string> substrings;

bool starts_with(string& a, string b) {
    for (int i=0; i<b.size(); ++i) if (a[i]!=b[i]) return false;
    return true;
}

bool ends_with(string& a, string b) {
    for (int i=0; i<b.size(); ++i) if (a[a.size()-b.size()+i]!=b[i]) return false;
    return true;
}

string combine(string& a, string& b) {
    if (a.find(b) != string::npos) return a;

    string ret = "";
    ret.resize(600);
    for (int i=0; i<b.length(); ++i) {
        if (starts_with(a, b.substr(i)) && ret.size()>i+a.size()) ret = b.substr(0, i)+a;
        if (ends_with(a, b.substr(0, i)) && ret.size()>a.size()+b.size()-i) ret = a+b.substr(i);
    }
    if (ret.size()==600) ret = a+b;
    return ret;
}

string word() {
    string ret = substrings[0];
    for (int i=1; i<k; ++i) ret = combine(ret, substrings[i]);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while(c--) {
        cin >> k; substrings.resize(k);
        for (int i=0; i<k; ++i) cin >> substrings[i];
        sort(substrings.begin(), substrings.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        cout << word() << endl;
    }
}