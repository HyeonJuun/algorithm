#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 250000 + 1;

int n, x;
int arr[MAX];
int prefix[MAX];
int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}
	int mx = -1, cnt = 0;
	for (int i = 1; i <= n - x + 1 ; i++)
	{
		int sum = prefix[i + x - 1] - prefix[i - 1];
		if (sum > mx)
		{
			mx = sum;
			cnt = 1;
		}
		else if (sum == mx)
		{
			cnt++;
		}
	}
	if (mx == 0)
		cout << "SAD" << '\n';
	else
	{
		cout << mx << "\n" << cnt;
	}
	return 0;
}