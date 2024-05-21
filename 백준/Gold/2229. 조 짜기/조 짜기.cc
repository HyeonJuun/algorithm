#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 10000 + 1

using namespace std;

int n;
int arr[MAX], dp[MAX];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 2; i <= n; i++)
    {
        int mn = arr[i], mx = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            mx = max(arr[j + 1], mx);
            mn = min(arr[j + 1], mn);
            dp[i] = max(dp[i], dp[j] + mx - mn);
        }
    }
    cout << dp[n] << endl;
    return 0;
}