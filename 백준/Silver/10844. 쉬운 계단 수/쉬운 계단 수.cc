#include <iostream>
using namespace std;


int main()
{

	int dp[101][10] = {};
	int n;
	int sum = 0;

	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][1];
			else if (j == 9)
				dp[i][9] = dp[i - 1][8];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[n][i]) % 1000000000;

	cout << sum % 1000000000;
}