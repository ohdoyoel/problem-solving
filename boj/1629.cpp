#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = unsigned long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// 오버플로우 처리를 위해 ulld 사용, 한 번 곱할 때마다 %c 해주기

lld a, b, c;

lld mult(lld a, lld b, lld c)
{
    if (b == 1) return a % c;
    lld x = mult(a, b / 2, c) % c;
    if (b % 2 == 1)
    {
        return ((a % c) * x % c * x % c) % c;
    }
    else
    {
        return (x * x % c) % c;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;

    cout << mult(a, b, c) << endl;

    return 0;
}