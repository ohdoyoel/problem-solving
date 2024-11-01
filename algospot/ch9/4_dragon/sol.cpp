#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 1000000050 + 1;
int length[51];
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

void calcLength() {
    length[0] = 1;
    for (int i=1; i<51; ++i) length[i] = min(MAX, 2*length[i-1]+2);
    return ;
}

char curve(string seed, int generation, int skip) {
    // cout << seed << endl;
    if (generation==0) return seed[skip];

    for (int i=0; i<seed.size(); ++i) {
        if (seed[i]=='X') {
            if (length[generation] <= skip) skip-=length[generation];
            else return curve(EXPAND_X, generation-1, skip);
        }
        else if (seed[i]=='Y') {
            if (length[generation] <= skip) skip-=length[generation];
            else return curve(EXPAND_Y, generation-1, skip);
        }
        else if (skip!=0) skip--;
        else return seed[i];
    }
    
    return '#';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    calcLength();
    int c; cin >> c;
    while(c--) {
        int n, p, l; cin >> n >> p >> l;
        for (int i=0; i<l; ++i) cout << curve("FX", n, p+i-1);
        cout << endl;
    }
}