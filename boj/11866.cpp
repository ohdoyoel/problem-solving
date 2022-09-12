#include <iostream>
#include <queue>
#include <vector>

int main()
{
    using namespace std;

    int a, b;
    queue<int> q;
    queue<int> debug_q;
    vector<int> ans;

    cin >> a >> b;

    for (uint i = 1; i <= a; i++) q.push(i);

    while (!q.empty())
    {
        for(uint i = 1; i < b; i++)
        {
            q.push(q.front());
            q.pop();
        }
        ans.push_back(q.front());
        q.pop();
    }
    
    cout << "<";
    for (uint i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans.back() << ">" << endl   ;

    return 0;
}