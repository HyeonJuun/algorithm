#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10001;

int n, k;
int dp[MAX] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	vector<int> money(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> money[i];
	}

	for (int i = 1; i <= k; i++)
		dp[i] = 10001;

	for (int i = 1; i <= n; i++)
	{
		for (int j = money[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - money[i]] + 1);
		}
	}

	if (dp[k] == 10001)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';
	return 0;
}