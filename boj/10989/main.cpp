#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// variable
///////////////////////////////////////
uint n;
vector<int> st;
vector<char> ans;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;
    vector<int> in(n);

    for (uint i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        in[i] = d;
    }

    // algorithm
    ///////////////////////////////////////
    uint i = 0;
    uint x = 1;
    while (i < n)
    {   
        if (n < x - 1)
        {
            ans.clear();
            cout << "NO" << endl;
            break;
        }
        if (st.empty())
        {
            st.push_back(x);
            x++;
            ans.push_back('+');
        }
        else
        {
            if (st.back() == in[i])
            {
                st.pop_back();
                ans.push_back('-');
                i++;
            }
            else
            {
                st.push_back(x);
                x++;
                ans.push_back('+');
            }
        }

    }

    // output
    ///////////////////////////////////////
    for (uint i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}

// pseudo code
///////////////////////////////////////
/*
n <- input
for (n times)
    in[i] <- input
for (n times)
    if (v.empty())
        v.push
    else
        if (v.top() == in[i])
            v.pop
        else 
            v.push()
*/