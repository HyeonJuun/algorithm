#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define endl "\n"
#define MAX 300000 + 10
#define INF 2100000000
#define MOD 1000000007

long long n;
long long arr[MAX];
long long two[MAX];
long long tmp = 1;
long long p, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        two[i] = tmp - 1;
        tmp *= 2;
        tmp %= MOD;
    }
    sort(arr, arr + n);

    for (int i = n - 1; i > 0; i--)
    {
        p += two[i] * arr[i];
        m += two[i] * arr[n - 1 - i];

        p %= MOD;
        m %= MOD;
    }
    cout << (p % MOD + MOD - m % MOD) % MOD << endl;
    return 0;
}