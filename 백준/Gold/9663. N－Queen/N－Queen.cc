#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>
#include<set>

using namespace std;

const int MAX = 15 + 1;


int n, ans = 0;
// 세로
int col[MAX];

bool check(int dep)
{
	for (int i = 0; i < dep; i++)
	{
		if (col[i] == col[dep] || abs(col[dep] - col[i]) == dep - i)
			return false;
	}
	return true;
}

void dfs(int dep)
{
	if (dep == n)
		ans++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			col[dep] = i;
			if (check(dep))
				dfs(dep + 1);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dfs(0);
	cout << ans << '\n';
	return 0;
}