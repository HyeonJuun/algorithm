#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000 + 1;
const int INF = 987654321;

int n;

int arr[MAX];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}