#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include <map>
#include<cmath>
using namespace std;

const int MAX = 100000 + 1;

int n;
long long arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long mn = 2000000000, ans = 0;

	int s = 0, e = n - 1;
	while (s < e)
	{
		long long sum = arr[s] + arr[e];
		if (abs(sum) < mn)
		{
			mn = abs(sum);
			ans = sum;

		}
		if (sum < 0)
			s++;
		else
			e--;
	}
	cout << ans;
	return 0;
}