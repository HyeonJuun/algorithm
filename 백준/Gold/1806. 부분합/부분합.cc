#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 100000 + 1;

int n;
int arr[MAX];
long long s;

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

		int start = 1, end = 1, ans = 987654321, sum = arr[1];
		while (start <= end && end <= n)
		{
			if (sum >= s)
			{
				ans = min(ans, end - start + 1);
			}
			if (sum < s)
			{
				end++;
				sum += arr[end];
			}
			else
			{
				sum -= arr[start];
				start++;
			}
		}
		if (ans == 987654321)
			cout << 0;
		else
			cout << ans;
	return 0;
}