#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define MAX 500 + 1

int n, m, answer;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int solve(int x, int y)
{
    if (x == n - 1 && y == m - 1)
        return 1;
    if (visited[x][y] != -1)
        return visited[x][y];

    visited[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        if (map[nx][ny] < map[x][y])
        {
            visited[x][y] += solve(nx, ny);
        }
    }
    return visited[x][y];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            visited[i][j] = -1;
        }
    }
    cout << solve(0, 0) << endl;
}
