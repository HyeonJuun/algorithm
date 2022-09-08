#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 100 + 1;


int n, k;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vector<int> v(n);
	vector<int>dp(k + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	dp[0] = 1;
	for (int i = 0; i <n; i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			dp[j] += dp[j - v[i]];
		}
	}
	cout << dp[k] << endl;
	return 0;
}