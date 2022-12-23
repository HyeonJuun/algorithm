#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int MAX = 9 + 1;

int t;

int map[MAX][MAX];
bool ans = true;
bool visited[MAX];

void Input()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> map[i][j];
		}
	}
}
void solve()
{
	//각 행 확인
	for (int i = 1; i <= 9; i++)
	{
		memset(visited, false, sizeof(visited));
		for (int j = 1; j <= 9; j++)
		{
			if (visited[map[i][j]] == true)
			{
				ans = false;
				return;
			}
			else
			{
				visited[map[i][j]] = true;
			}
		}
	}
	//각 열 확인
	for (int i = 1; i <= 9; i++)
	{
		memset(visited, false, sizeof(visited));
		for (int j = 1; j <= 9; j++)
		{
			if (visited[map[j][i]] == true)
			{
				ans = false;
				return;
			}
			else
			{
				visited[map[j][i]] = true;
			}
		}
	}
	// 작은 정사각형 확인
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			memset(visited, false, sizeof(visited));
			for (int j = 1; j <= 3; j++)
			{
				for (int k = 1; k <= 3; k++)
				{
					//cout << "indY : " << (i * 3) + j << " indX : " << (x * 3) + k;
					if (visited[map[(i * 3) + j][(x * 3) + k]] == true)
					{
						ans = false;
						return;
					}
					else
					{
						visited[map[(i * 3) + j][(x * 3) + k]] = true;
					}
				}
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int i=1; i<=t; i++)
	{
		ans = true;
		memset(map, 0, sizeof(map));
		Input();
		solve();
		if (ans)
			cout << "Case " << i << ": CORRECT" << '\n';
		else
			cout << "Case " << i << ": INCORRECT" << '\n';

	}
	return 0;
}