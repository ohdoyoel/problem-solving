#include <iostream>
#include <deque>
#include <utility>

int main()
{
    using namespace std;

    uint n;
    cin >> n;
    deque<pair<int, int>> d;

    for (uint i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        d.push_back(make_pair(i, x));
    }

    string ans;
    uint i = 0;

    while (!d.empty())
    {
        auto cur = d.front();
        cout << cur.first << ' ';
        d.pop_front();
        if (cur.second > 0)
        {
            for (uint i = 0; i < cur.second - 1; i++)
            {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else
        {
            for (int i = cur.second; i < 0; i++)
            {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }

    return 0;
}