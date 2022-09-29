#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long> v;
	long long n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++)
	{
		long long s, l, c;
		cin >> s >> l >> c;
		for (int j = 0; j < c; j++)
		{
			long long bus = s + l * j;
			v.push_back(bus);
		}
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size();
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (v[mid] >= t)
			end = mid;
		else
			start = mid + 1;
	}
	if (v[start] - t < 0)
	{
		cout << -1 << endl;
	}
	else
		cout << v[start] - t << endl;
	return 0;
}