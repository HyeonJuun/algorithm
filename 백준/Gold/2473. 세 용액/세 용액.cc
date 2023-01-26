#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include <map>
#include<cmath>
using namespace std;

const int MAX = 5000 + 1;

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
	int s = 0, e = n - 1;
	int ans1, ans2, ans3;
	long long mn = 3000000000;
	for (int i = 0; i < n; i++)
	{
		int s = i + 1, e = n - 1;
		while (s < e)
		{
			long long sum = arr[i] + arr[s] + arr[e];
			if (abs(sum) < mn)
			{
				ans1 = arr[i];
				ans2 = arr[s];
				ans3 = arr[e];
				mn = abs(sum);
			}
			if (sum < 0)
				s++;
			else
				e--;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3;
	return 0;
}