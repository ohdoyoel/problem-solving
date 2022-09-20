#include <iostream>
#include <vector>
#include <utility>

bool compare(pair<string, int>a, pair<string, int>b) {
	return a.second < b.second;
}

int main()
{
    using namespace std;

    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> d;
    vector<pair<string, int>> b;
    vector<string> ans;

    for (uint i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        int code = 5381;
        for (uint j = 0; j < x.length(); j++)
        {
            code = (((code << 5) + code) + x[j]) % 8191;
        }
        d.push_back(make_pair(x, code));
    }

    for (uint i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        int code = 5381;
        for (uint j = 0; j < x.length(); j++)
        {
            code = (((code << 5) + code) + x[j]) % 8191;
        }
        b.push_back(make_pair(x, code));
    }

    sort(d.begin(), d.end(), compare);
    sort(b.begin(), b.end(), compare);

    int smaller_index = min(n, m);
    auto smaller = d if (n < m) else b;

    for (uint i = 0; i < smaller_index; i++)
    {
        smaller[i].second
    }

    return 0;
}