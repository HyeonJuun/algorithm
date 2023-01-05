#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 10000 + 1;

int n;

int arr[MAX];
int dp[MAX][3] = { 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1][1] = arr[1];
	dp[2][1] = arr[2];
	dp[2][2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 2][1], max(dp[i - 1][0], dp[i - 1][2]));
		dp[i][1] = max(dp[i - 1][0], max(dp[i - 2][1], dp[i - 2][2])) + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	int ans = -1;
	for (int i = 0; i < 3; i++)
	{
		if (ans < dp[n][i])
			ans = dp[n][i];
	}
	cout << ans;
	return 0;
}