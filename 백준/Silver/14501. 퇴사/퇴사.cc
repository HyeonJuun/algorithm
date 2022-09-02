#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;

int n;

int main() {
	int dp[16] = { 0, };
	int pay[16] = { 0, };
	int time[16] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++)
		{
			if (time[j] + j <= i && i + time[i] <= n + 1)
				dp[i] = max(dp[i], dp[j] + pay[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}