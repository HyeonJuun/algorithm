#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100 + 1;

int n;
long long dp[MAX][21] = { 0 };
int arr[MAX];
long long ans = 0;

void solve()
{
	dp[0][arr[0]] = 1;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j] != 0)
			{
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	solve();
	cout << dp[n - 2][arr[n - 1]] << '\n';
	return 0;
}