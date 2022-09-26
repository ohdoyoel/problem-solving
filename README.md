# problem_solving

## 1. Introduction

풀어본 문제의 코드를 저장하는 레포지토리입니다.

## 2. Skeleton Code

```c++
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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////


    // algorithm
    ///////////////////////////////////////
    

    // output
    ///////////////////////////////////////
    

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/
```

PS 장인 한동규 씨로부터 영감을 받아 작성되었습니다.

## 3. Input Tips

### 1. 정수 입력 받기

```c++
int n;
cin >> n;
```

정수를 입력 받을 때마다 `cin >> 변수` 처리를 해주면 됩니다.

### 2. 정수 n개를 입력 받아 데이터에 저장하기

```c++
int n;
cin >> n;
vector<int> v(n); // 미리 사이즈 명시해주기!
for (uint i = 0; i < n; i++)
{
  cin >> v[i];
}
```

for문을 돌려 벡터에 저장해주면 됩니다.

> 왠만한 가변 길이 데이터를 저장하는 는 벡터를 쓰면 됩니다.
