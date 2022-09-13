#include <iostream>
#include <stack>

// 기본적으로 괄호 문제처럼 접근
// bomb 길이가 ㅉ, ㅎ 경우 나누기
// bomb 길이가 ㅉ이면 절반 앞 문자열들에 대하여 스택 저장
// bomb 길이가 ㅎ이면 절반 앞 문자열들에 대하여 스택 저장
// 절반 뒤가 나오면 스택에서 꺼내서 확인

int main()
{
    using namespace std;

    string str;
    string bomb_str;

    stack<char> s;

    cin >> str >> bomb_str;
    
    uint bomb_len = bomb_str.length();

    for (uint i = 0; i < str.length(); i++)
    {
        s.push(str[i]);

        if (s.top() == bomb_str[bomb_len - 1] && s.size() >= bomb_len)
        {
            bool flag = true;
            for (uint j = 0; j < bomb_len - 1; j++)
            {
                if (str[i - 1 - j] != bomb_str[bomb_len - 2 - j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (uint i = 0; i < bomb_len; i++) s.pop();
            }
        }
    }

    uint ans_len = s.size();
    char *ans = new char[ans_len];
    if (ans_len == 0) cout << "FRULA";
    else
    {
        for (uint i = 0; i < ans_len; i++)
        {
            ans[i] = s.top();
            s.pop();
        }
        for (int j = ans_len - 1; j >= 0; j--) cout << ans[j];
    }
    cout << endl;
    return 0;
}