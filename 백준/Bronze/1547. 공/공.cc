#include<iostream>
#include<string>

using namespace std;

int main()
{
	int m, ans = 1;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x == ans)
		{
			ans = y;
		}
		else if (y == ans)
		{
			ans = x;
		}

	}
	cout << ans;
	return 0;
}