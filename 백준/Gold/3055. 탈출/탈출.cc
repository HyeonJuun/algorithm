#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 50 + 1;

char map[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int r, c, cnt = 0;
string str;

// 비버 위치
pair<int, int> beaver;
//물 움직이는 큐
queue<pair<int, int>> water_q;
//고슴도치 움직이는 큐
queue<pair<int, int>> h_q;

void bfs()
{
	while (!h_q.empty())
	{
		int water_cnt = water_q.size();
		for (int i = 0; i < water_cnt; i++)
		{
			int cur_waterX = water_q.front().first;
			int cur_waterY = water_q.front().second;

			water_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int n_waterX = cur_waterX + dx[i];
				int n_waterY = cur_waterY + dy[i];

				if (n_waterX < 0 || n_waterY < 0 || n_waterX >= r || n_waterY >= c)
					continue;
				if (map[n_waterX][n_waterY] == '.')
				{
					water_q.push(make_pair(n_waterX, n_waterY));
					map[n_waterX][n_waterY] = '*';
				}
			}
		}
		int h_cnt = h_q.size();
		for (int i = 0; i < h_cnt; i++)
		{
			int cur_hX = h_q.front().first;
			int cur_hY = h_q.front().second;

			h_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int n_hX = cur_hX + dx[i];
				int n_hY = cur_hY + dy[i];

				if((n_hX == beaver.first) && (n_hY == beaver.second))
				{
					cnt++;
					cout << cnt << endl;
					return;
				}

				if (n_hX < 0 || n_hY < 0 || n_hX >= r || n_hY >= c)
					continue;
				if (map[n_hX][n_hY] == '.')
				{
					h_q.push(make_pair(n_hX, n_hY));
					map[n_hX][n_hY] = 'S';
				}
			}
		}
		cnt++;
	}
	cout << "KAKTUS" << endl;
	return;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = str[j];
			if (str[j] == 'S')
				h_q.push(make_pair(i, j));
			else if (str[j] == 'D')
				beaver = make_pair(i, j);
			else if (str[j] == '*')
				water_q.push(make_pair(i, j));
		}
	}
	bfs();
	return 0;
}