#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 1000 + 1;

int c, n;
int ans[MAX];

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	ans[1] = 3;
	for (int i = 2; i < MAX; i++)
	{
		int cnt = 0;
		for (int j = 1; j < i; j++)
		{
			if (gcd(i, j) == 1)
			{
				cnt++;
			}
		}
		ans[i] = ans[i - 1] + 2 * cnt;

	}
	while (c--)
	{
		cin >> n;
		cout << ans[n] << '\n';
	}
	return 0;
}