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
string input;
int x;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;

    // algorithm
    ///////////////////////////////////////
    for (uint i = 0; i < n; i++)
    {
        cin >> input;
        if (input == "push_front")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if (input == "push_back")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (input == "pop_front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (input == "pop_back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (input == "size")
        {
            cout << dq.size() << endl;
        }
        else if (input == "empty")
        {
            cout << dq.empty() << endl;
        }
        else if (input == "front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (input == "back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    // output
    ///////////////////////////////////////

    return 0;
}