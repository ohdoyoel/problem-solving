#include <iostream>
#include <stack>

int main()
{
    using namespace std;

    string input;

    while(getline(cin, input))
    {
        bool flag = true;
        stack<char> s;

        if (input == ".") break;
        for(uint i = 0; i < input.size(); i++)
        {
            if (input[i] == '[' || input[i] == '(') s.push(input[i]);
            if (input[i] == ']')
            {
                if (s.empty())
                {
                    flag = false;
                    break;
                }
                else
                {
                    if (s.top() == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (input[i] == ')')
            {
                if (s.empty())
                {
                    flag = false;
                    break;
                }
                else
                {
                    if (s.top() == '(')
                    {
                        s.pop();
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (s.empty() && flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}