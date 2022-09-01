#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;

int dp[MAX];
vector<int> v;

int n, x, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
		int dp_max = 0;

		for (int j = 0; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				if (dp_max < dp[j])
					dp_max = dp[j];
			}
		}
		dp[i] = dp_max + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}