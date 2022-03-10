#include<iostream>
#include<string>
#include <cmath>

using namespace std;
int N[1001] = { 0,1,  };
int main()
{
	int n, k, cnt=0, ans =0;
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
	{
		N[i] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (N[i] != 0)
		{
			for (int j = 1; j <= n / i; j++)
			{
				if (N[i * j] != 0)
				{
					cnt++;
					ans = N[i * j];
					N[i * j] = 0;
				}
				if (cnt == k)
				{
					cout << ans << endl;
					break;
				}
			}
		}
	}
	return 0;
}