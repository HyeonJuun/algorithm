#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 250;

int R, C;

int sheep, wolf;

string graph[MAX];

bool visited[MAX][MAX];

typedef struct
{
	int y, x;

}Dir;



Dir moveDir[4] = { {1,
0}, {-1, 0}, {0, 1}, {0, -1} };



void BFS(int y, int x)
{
	int curSheep = 0, curWolf = 0;

	queue <pair<int, int>> q; //y, x
	q.push({ y, x });
	visited[y][x] = true;
	if (graph[y][x] == 'k')
		curSheep++;
	else if (graph[y][x] == 'v')
		curWolf++;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveDir[i].y;
			int nextX = curX + moveDir[i].x;

			if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C && !visited[nextY][nextX] && graph[nextY][nextX] != '#')
			{
				visited[nextY][nextX]= true;
				if (graph[nextY][nextX] == 'k')
					curSheep++;
				else if (graph[nextY][nextX] == 'v')
					curWolf++;
				q.push({ nextY,nextX });
			}

		}

	}

	if (curSheep >curWolf)
		wolf-= curWolf;
	else
		sheep-= curSheep;

}



int main(void)
{
	cin >> R >> C;
	
	for (int i = 0; i < R;i++)
	{
		cin>> graph[i];

		for (int j = 0; j < C; j++)
			if (graph[i][j] == 'k')
				sheep++;
			else if (graph[i][j] == 'v')
				wolf++;
	}

	for (int i = 0; i < R;i++)
		for (int j = 0; j < C;j++)
			if ((graph[i][j] == 'k' || graph[i][j] == 'v') &&!visited[i][j])
				BFS(i,j);

	cout << sheep << " " << wolf << "\n";

	return 0;

}
