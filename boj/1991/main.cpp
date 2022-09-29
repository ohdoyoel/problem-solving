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
int n;
int arr[26][2];

void preOrder(int i)
{
    if (i == -1) return;
    cout << (char)(i + 'A');
    preOrder(arr[i][0]);
    preOrder(arr[i][1]);
}

void inOrder(int i)
{
    if (i == -1) return;
    inOrder(arr[i][0]);
    cout << (char)(i + 'A');
    inOrder(arr[i][1]);
}

void postOrder(int i)
{
    if (i == -1) return;
    postOrder(arr[i][0]);
    postOrder(arr[i][1]);
    cout << (char)(i + 'A');
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    // input
    ///////////////////////////////////////
    cin >> n;

    // algorithm
    ///////////////////////////////////////
    for (int i = 0; i < n; i++)
    {
        char n, l, r;
        cin >> n >> l >> r;
        if (l == '.') arr[n - 'A'][0] = -1;
        else arr[n - 'A'][0] = l - 'A';
        if (r == '.') arr[n - 'A'][1] = -1;
        else arr[n - 'A'][1] = r - 'A';
    }

    // output
    ///////////////////////////////////////
    preOrder(0);
    cout << endl;
    inOrder(0);
    cout << endl;
    postOrder(0);
    cout << endl;

    return 0;
}

// pseudo code
///////////////////////////////////////
/*

*/