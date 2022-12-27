#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>
#define mod 1000000009

using namespace std;

const int MAX = 100000 + 1;

int n, t;
long long dp[MAX][4];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		long long ans = 0;
		cin >> n;
		dp[1][1] = 1;
		dp[1][2] = dp[1][3] = 0;
		dp[2][1] = dp[2][3] = 0;
		dp[2][2] = 1;
		dp[3][1] = dp[3][2] = dp[3][3] = 1;
		for (int i = 4; i <= n; i++)
		{
			dp[i][1] = (dp[i - 1][2] % mod) + (dp[i - 1][3] % mod) % mod;
			dp[i][2] = (dp[i - 2][1] % mod) + (dp[i - 2][3] % mod) % mod;
			dp[i][3] = (dp[i - 3][1] % mod) + (dp[i - 3][2] % mod) % mod;
		}
		for (int i = 1; i <= 3; i++)
		{
			ans = (ans + dp[n][i]) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}