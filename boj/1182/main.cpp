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
int n, s;
int sum = 0;
int res = 0;
vector<int> seq;

void solve(int k)
{
    if (k == n) // n개까지 순회함
    {
        if (sum == s){res++;} 
        return ;
    }
    sum += seq[k];
    solve(k + 1);
    //
    sum -= seq[k];
    solve(k + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seq.push_back(x);
    }


    // algorithm
    ///////////////////////////////////////
    solve(0);

    // output
    ///////////////////////////////////////
    if (s == 0) cout << res - 1 << endl;
    else cout << res << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*
- 매 순간마다 더할지 말지를 체크
- 이러한 풀이가 가능한 이유는 부분 수열의 길이가 주어지지 않았기 때문
- 부분 수열 내에 순서가 정해지지 않았기 때문에 (집합의 개수를 찾는 것이기 때문에) 이전 문제들 처럼 주어진 수열을 순회할 필요 X
- 만약 합이 0이어야 할 경우 하나씩 더 카운트 됨. 왜냐하면 공집합이 카운트되기 때문!
*/