#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;

int t, n, x, ans = 0, ind;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int dp[2][MAX];

		dp[0][0] = dp[1][0] = 0;
		for (int i = 1; i <= n; i++)
			cin >> dp[0][i];
		for (int i = 1; i <= n; i++)
			cin >> dp[1][i];
		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + dp[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + dp[1][i];
		}
		ans = max(dp[1][n], dp[0][n]);
		cout << ans << endl;
	}
	return 0;
}