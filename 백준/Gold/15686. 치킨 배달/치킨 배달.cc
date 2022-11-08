#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 50 + 1;

int n, m, x, ans = 987654321;

int map[MAX][MAX];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> chosen;
bool selected[13];

int Dist(pair<int, int> h, pair<int, int> chose)
{
	return abs(h.first - chose.first) + abs(h.second - chose.second);
}
void solve(int dep, int ind)
{
	if (dep == m)
	{
		int chickenDist = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int minDist = 987654321;
			for (int j = 0; j < chosen.size(); j++)
			{
				minDist = min(minDist, Dist(house[i], chosen[j]));
			}
			chickenDist += minDist;
		}
		ans = min(ans, chickenDist);
		return;
	}

	for (int i = ind; i < chicken.size(); i++)
	{
		int x = chicken[i].second;
		int y = chicken[i].first;

		if (selected[i] == true)
			continue;


		selected[i] = true;
		chosen.push_back({ chicken[i].first, chicken[i].second });
		solve(dep + 1, i + 1);
		selected[i] = false;
		chosen.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ i, j });
			if (map[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}
	solve(0, 0);
	cout << ans << '\n';
	return 0;
}