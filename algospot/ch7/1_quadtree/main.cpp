#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (uint)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string vectorStringToString(vector<string> v) {
    string result = "";
    for (string s : v) {
        result += s;
    }
    return result;
}

string flipUpDown(string line) {
    if(sz(line) == 1) return line;

    vector<string> quad;
    int i = 0;
    while(i < sz(line)) {
        if (sz(quad) == 4) break;
        
        string quadItem = "";
        
        if (line[i] == 'x') quadItem = flipUpDown(line.substr(i + 1));
        else quadItem = line[i];
        
        quad.push_back(quadItem);
        i += sz(quadItem);
    }

    cout << quad[0] << " " << quad[1] << " " << quad[2] << " " << quad[3] << endl;

    string fst = quad[0];
    string scd = quad[1];
    quad[0] = quad[2];
    quad[1] = quad[3];
    quad[2] = fst;
    quad[3] = scd;
    
    cout << quad[0] << " " << quad[1] << " " << quad[2] << " " << quad[3] << endl;
    
    if (line[0] == 'x') return 'x' + vectorStringToString(quad);
    else return vectorStringToString(quad);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string l;
        cin >> l;
        cout << flipUpDown(l) << endl;;
    }

    return 0;
}