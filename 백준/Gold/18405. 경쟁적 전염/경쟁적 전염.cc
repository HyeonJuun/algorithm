#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

int map[201][201] = { 0, };

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int n, k;

int x, y, s;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	vector<pair<int, pair<int, int>>> virus;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
				virus.push_back({ map[i][j], {i, j} });
		}
	}
	cin >> s >> y >> x;
	sort(virus.begin(), virus.end());
	int curTime = 0;
	while (curTime < s)
	{
		int vCnt = virus.size();
		for (int i = 0; i < vCnt; i ++)
		{
			int curVirus = virus[i].first;
			int curY = virus[i].second.first;
			int curX = virus[i].second.second;
			
			for (int i = 0; i < 4; i++)
			{
				int ny = curY + dy[i];
				int nx = curX + dx[i];

				if (nx<1 || ny <1 || nx> n || ny > n)
					continue;
				if (map[ny][nx])
					continue;
				map[ny][nx] = curVirus;
				virus.push_back({ curVirus, {ny, nx} });
			}
		}
		if (map[y][x])
			break;
		curTime++;
	}

	cout << map[y][x] << endl;
	return 0;
}