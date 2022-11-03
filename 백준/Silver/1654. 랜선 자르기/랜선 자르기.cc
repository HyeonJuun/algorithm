#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const long long MAX = 1000000000 + 1;

long long n, k;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	vector<long long> v(k);
	long long maxN = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
		if (maxN < v[i])
			maxN = v[i];
	}
	long long ans = 0, left = 1, right = maxN;

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
	cout << ans << '\n';
	return 0;
}