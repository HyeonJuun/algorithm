#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 501;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int map[MAX][MAX] = { 0, };

bool visited[MAX][MAX] = { false, };

queue<pair<int, int> > q;
vector<int> v;

int n, m, k, cnt = 0, ans = 0;
void bfs(int y, int x)
{
	q.push(make_pair(y, x));
	visited[y][x] = true;

	cnt = 1;
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && map[i][j])
			{
				cnt = 1;
				bfs(i, j);
				ans++;
			}
		}
	}
		cout << ans << endl;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;

		}

	return 0;
}
