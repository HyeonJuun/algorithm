#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 500 + 1;

int dp[MAX][MAX];
int arr[MAX][MAX];
int n, x, ans=0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}
	ans = dp[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i+1; j++)
		{
			if (j == 1)
				dp[i][j] += dp[i - 1][j];
			else if (i == j)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);

			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}