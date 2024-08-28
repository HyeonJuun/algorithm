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

#define MAX 5000 + 10
#define INF 987654321

int dp[MAX];
int arr[MAX];
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for (int i = 1; i <= str.length(); i++)
    {
        arr[i] = str[i - 1] - '0';
    }
    if (str.length() == 1 && str[0] == '0')
    {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;

    for (int i = 1; i <= str.length(); i++)
    {
        if (arr[i] >= 1 && arr[i] <= 9)
        {
            dp[i] = (dp[i - 1] + dp[i]) % 1000000;
        }
        if (i == 1)
            continue;

        int tmp = arr[i] + arr[i - 1] * 10;
        if (tmp >= 10 && tmp <= 26)
        {
            dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }
    cout << dp[str.length()] << endl;
    return 0;
}