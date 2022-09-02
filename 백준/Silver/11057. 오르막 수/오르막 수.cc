#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;
int mod = 10007;
int n, sum = 0;
int dp[MAX][10];
int main() {
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j ; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		sum =(sum +  dp[n][i]) % mod;
	}
	cout << sum % mod << endl;
	return 0;
}