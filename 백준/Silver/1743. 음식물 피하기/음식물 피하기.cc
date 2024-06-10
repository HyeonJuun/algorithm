#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100 + 1

using namespace std;

int n, m, k, answer;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int solve(int x, int y)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    // cout << "x : " << x << " y : " << y << endl;
    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx <= 0 || ny <= 0 || nx > n || ny > m || map[nx][ny] == 0)
                continue;

            if (!visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
            {
                int x = solve(i, j);
                answer = max(answer, x);
            }
        }
    }
    cout << answer << endl;
    return 0;
}