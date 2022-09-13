#include <iostream>
#include <stack>

// 기본적으로 괄호 문제처럼 접근
// bomb 길이가 ㅉ, ㅎ 경우 나누기
// bomb 길이가 ㅉ이면 

int main()
{
    using namespace std;

    string str;
    string bomb_str;
    uint bomb_len = bomb_str.size();
    stack<char> s;

    if (bomb_len % 2 == 0)
    {
        for (uint i = 0; i < str.size(); i++)
        {
            for (uint j = 0; j < bomb_len; j++)
            {
                if (str[i] == bomb_str[j])
                {
                    if (j < bomb_len / 2) s.push(str[i]);
                    else
                    {
                        if (str[i] == s.top())
                        {
                            s.pop();
                        }
                        else
                        {

                        }
                    }
                } 
            }
        }
    }
    return 0;
}