#include <iostream>
#include <stack>
#include <vector>

// Double이 아니라 Float을 써서 삽질함...

int main()
{
    using namespace std;

    uint n;
    string str;
    stack<double> s;
    int num[26];
    cin >> n >> str;
    for (uint i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (uint i = 0; i < str.length(); i++)
    {
        if (65 <= str[i] && str[i] <= 90)
        {
            s.push(num[str[i] - 65]);
        }
        if (!s.empty())
        {
            if (str[i] == '+')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (str[i] == '-')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(b - a);
            }
            else if (str[i] == '*')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (str[i] == '/')
            {
                double a = s.top();
                s.pop();
                double b = s.top();
                s.pop();
                s.push(b / a);
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << endl;

    return 0;
}