#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 7 + 1;

int n;
int ans = 0;
bool flag = false;
char map[MAX][MAX];
vector<pair<int, int>> t, blank;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool see(int nx, int ny, int dir)
{
	while (true)
	{
		nx += dx[dir];
		ny += dy[dir];
		if (map[nx][ny] == 'O' || nx < 0 || ny < 0 || ny >= n || nx >= n)
			break;
		if (map[nx][ny] == 'S')
			return true;
	}
	return false;
}
bool ck()
{
	for (int i = 0; i < t.size(); i++)
	{
		int x = t[i].first;
		int y = t[i].second;
		for (int j = 0; j < 4; j++)
		{
			if (see(x, y, j))
				return false;
		}
	}
	return true;
}
void solve(int num)
{
	if (num == 3)
	{
		// 장애물 설치 다했다면 다 가릴 수 있는지 확인
		if (ck())
		{
			flag = true;
		}
		return;
	}
	for (int i = 0; i < blank.size(); i++)
	{
		int x = blank[i].first;
		int y = blank[i].second;

		if (map[x][y] == 'X')
		{
			map[x][y] = 'O';
			solve(num + 1);
			map[x][y] = 'X';
		}
	}
}



int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'T')
				t.push_back({ i, j });
			else if (map[i][j] == 'X')
				blank.push_back({ i, j });
		}
	}
	solve(0);
	if (flag == true)
	{
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}