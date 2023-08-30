#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

string str;
long long ans = 0;

void dfs(int cur, int m, int j, bool l, long long cnt)
{
	if (cur == str.length())
	{
		if (l)
			ans += cnt;
		return;
	}

	char c = str[cur];

	if (c == '_')
	{
		bool ma = true;
		bool ja = true;
		if (m == 2)
			ma = false;
		if (j == 2)
			ja = false;
		if (ma)
			dfs(cur + 1, m + 1, 0, l, cnt * 5);
		if (ja)
		{
			dfs(cur + 1, 0, j + 1, true, cnt);
			dfs(cur + 1, 0, j + 1, l, cnt * 20);
		}
	}
	else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
	{
		if (m == 2)
			return;
		dfs(cur + 1, m + 1, 0, l, cnt);
	}
	else
	{
		if (j == 2)
			return;
		if (c == 'L')
			dfs(cur + 1, 0, j + 1, true, cnt);
		else
			dfs(cur + 1, 0, j + 1, l, cnt);
	}
}
int main()
{
	cin >> str;
	dfs(0, 0, 0, false, 1);
	cout << ans << endl;
	return 0;
}
