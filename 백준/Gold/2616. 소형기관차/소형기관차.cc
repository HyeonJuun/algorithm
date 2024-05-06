#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50000 + 1;

int arr[MAX];
int dp[4][MAX];
int n, x;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        arr[i] = arr[i - 1] + tmp;
    }
    cin >> x;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = i * x; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - x] + (arr[j] - arr[j - x]));
        }
    }
    cout << dp[3][n] << endl;
    return 0;
}
