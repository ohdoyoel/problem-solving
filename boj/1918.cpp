#include <iostream>
#include <stack>

// https://programforlife.tistory.com/65

int main()
{
    using namespace std;

    string str;
    cin >> str;

    stack<char> s;
    string ans;
    
    for (uint i = 0; i < str.length(); i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            ans += str[i];
        }
        else
        {
            if (str[i] == '+' || str[i] == '-')
            {
                while(!s.empty() && s.top() != '(')
                {
                    ans += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == '*' || str[i] =='/')
            {
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    ans += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                while (!s.empty() && (s.top() != '('))
                {
                    ans += s.top();
                    s.pop();
                }
                s.pop();
            }
            else if (str[i] == '(')
            {
                s.push(str[i]);
            }
        }
    }

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    cout << ans << endl;

    return 0;
}