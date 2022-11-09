#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10 + 1;

int n, m, x, ans = 987654321;

int map[MAX][MAX];
bool visited[MAX];
vector<int> dist;
int start_city;

void solve(int ind, int dep, int cost)
{
	if (dep == n)
	{
		if (map[ind][start_city] > 0)
			ans = min(cost + map[ind][start_city], ans);
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (map[ind][i] == 0 || visited[i] == true)
			continue;

		visited[i] = true;
		solve(i, dep + 1, cost + map[ind][i]);
		visited[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		start_city = i;
		visited[i] = true;
		solve(i, 1, 0);
		visited[i] = false;
	}
	cout << ans << '\n';
	return 0;
}