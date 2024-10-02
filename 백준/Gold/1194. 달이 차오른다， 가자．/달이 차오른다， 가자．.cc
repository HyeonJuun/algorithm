#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define MAX 100 + 10
#define INF 987654321

char mp[MAX][MAX];
int visited[MAX][MAX][65];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;

void bfs(pair<int, int> start, int dist, int keys)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second][keys] = dist + 1;

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            char nc = mp[nx][ny];
            if (nc == '#')
                continue;

            // 문
            if (nc >= 'A' && nc <= 'Z')
            {
                int key = nc - 'A';
                if (keys & (1 << key))
                {
                    if (visited[nx][ny][keys] == 0 ||
                        visited[nx][ny][keys] > visited[curx][cury][keys] + 1)
                    {
                        mp[nx][ny] = '.';
                        bfs({nx, ny}, visited[curx][cury][keys], keys);
                        mp[nx][ny] = nc;
                    }
                }
            }
            else if ('a' <= nc && nc <= 'z')
            {
                int key = nc - 'a';
                int new_key = keys | (1 << key);

                if (visited[nx][ny][new_key] == 0 ||
                    visited[nx][ny][new_key] > visited[curx][cury][keys] + 1)
                {
                    bfs({nx, ny}, visited[curx][cury][keys], new_key);
                }
            }
            else
            {
                if (visited[nx][ny][keys] == 0 || visited[nx][ny][keys] > visited[curx][cury][keys] + 1)
                {
                    q.push({nx, ny});
                    visited[nx][ny][keys] = visited[curx][cury][keys] + 1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '0')
            {
                start.first = i;
                start.second = j;
            }
        }
    }

    bfs(start, 0, 0);

    int answer = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '1')
            {
                for (int k = 0; k < 64; k++)
                {
                    if (visited[i][j][k] != 0)
                    {
                        answer = min(answer, visited[i][j][k] - 1);
                    }
                }
            }
        }
    }
    if (answer == INF)
        answer = -1;

    cout << answer << endl;
    return 0;
}