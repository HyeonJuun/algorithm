#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 20 + 1;

int n;
int arr[MAX][MAX];
int team[MAX];
int mn_ans = 1000000000;

void solve(int dep, int pos)
{
	if (dep <= n)
	{
		int start_sum = 0, link_sum = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (team[i] == 1 && team[j] ==1)
					start_sum += arr[i][j];
				if (team[i] == 0 && team[j] == 0)
					link_sum += arr[i][j];
			}
		}
		int sub_team = abs(start_sum - link_sum);
		if (mn_ans > sub_team)
			mn_ans = sub_team;

	}
	for (int i = pos; i <= n; i++)
	{
		team[i] = 1;
		solve(dep + 1, i + 1);
		team[i] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	solve(0, 1);
	cout << mn_ans;
	return 0;
}