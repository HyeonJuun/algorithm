#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 100000 + 1;

long long n, m;
long long arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long low = -1, high = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		high += arr[i];
		low = max(low, arr[i]);
	}
		

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long cnt = 0, sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + arr[i] > mid)
			{
				cnt++;
				sum = 0;
			}
			sum += arr[i];
		}
		if (sum != 0)
			cnt++;

		if (cnt <= m)
		{
			high = mid - 1;	
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << low;
	return 0;
}