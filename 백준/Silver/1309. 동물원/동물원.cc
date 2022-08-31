#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>

using namespace std;

const int MAX = 100000 + 1;

int dp[MAX][3];

int n;

int main() 
{
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901 << endl;
    return 0;

}