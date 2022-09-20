#include <iostream>
#include <bits/stdc++.h>
#include <stack>

int main()
{
    using namespace std;

    string str;
    string bomb_str;

    stack<char> s;

    cin >> str >> bomb_str;
    
    uint bomb_len = bomb_str.length();

    // 만약 bomb 마지막 문자가 들어오면 뒤쪽으로 bomb 문자열 있는지 확인
    // 있으면 삭제
    // 없으면 넘어가기
    for (uint i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
        bool flag = true;

        if (s.top() == bomb_str[bomb_len - 1] && s.size() >= bomb_len)
        {
<<<<<<< HEAD
            string k;
            for (uint j = 0; j < bomb_len; j++)
            {
                k += 
                if (str[i - j] != bomb_str[bomb_len - 1 - j])
=======
            string v;
            for (uint i = 0; i < bomb_len; i++)
            {
                v += s.top();
                s.pop();
            }
            reverse(v.begin(), v.end());
            for (int i = 0; i < bomb_len; i++)
            {
                if (v[i] != bomb_str[i])
>>>>>>> f3b48a51cb8c3224a7932b5176183f2d52b7743b
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) for (uint i = 0; i < bomb_len; i++) s.push(v[i]);
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