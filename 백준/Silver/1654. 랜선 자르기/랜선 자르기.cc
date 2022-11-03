#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

const int MAX = 1000000000 + 1;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	long long k, n;
	vector<long long>  v;
	cin >> k >> n;
	long long maxn = 0;
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
		if (x >= maxn)
			maxn = x;

	}
	long long ans = 0;
	long long left = 1;
	long long right = maxn;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += v[i] / mid;
		}
		if (sum >= n)
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans << endl;
	return 0;

}