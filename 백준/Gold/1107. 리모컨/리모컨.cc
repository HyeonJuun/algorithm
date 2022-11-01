#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000002;

int n, m, ans = 0;
char button[11];

int check(int n)
{
	if (n == 0)
	{
		if (button[0])
			return 0;
		else
			return 1;
	}
		int len = 0;
		while (n > 0)
		{
			if (button[n % 10])
				return 0;
			n /= 10;
			len++;
		}
	return len;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		button[x] = true;
	}
	ans = n - 100;
	if (ans < 0)
		ans = -ans;
	for (int i = 0; i <= 10000000; i++)
	{
		int c = i;
		int len = check(c);
		if (len > 0)
		{
			int press = abs(c - n);
			if (ans > press + len)
			{
				ans = press + len;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}