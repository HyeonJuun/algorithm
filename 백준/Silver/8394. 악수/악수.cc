#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 10000000 + 1;

int n;
int dp[MAX];

int main() 
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    }
    cout << dp[n] << endl;
    return 0;

}