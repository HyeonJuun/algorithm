#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

#define MAX 1000 + 10
#define INF 2e9
using namespace std;

int r, c, answer = INF;
string mp[MAX];
int dist_j[MAX][MAX];
int dist_f[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int, int>> q_f;
bool flag = false;
queue<pair<int, int>> q_j;
void bfs()
{
    while (!q_f.empty())
    {
        int curx = q_f.front().first;
        int cury = q_f.front().second;
        q_f.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c || mp[nx][ny] == '#' || dist_f[nx][ny] >= 0)
                continue;

            dist_f[nx][ny] = dist_f[curx][cury] + 1;
            q_f.push({nx, ny});
        }
    }

    while (!q_j.empty())
    {
        int curx = q_j.front().first;
        int cury = q_j.front().second;
        q_j.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            {
                answer = dist_j[curx][cury] + 1;
                flag = true;
                break;
            }
            if (mp[nx][ny] == '#' || dist_j[nx][ny] >= 0)
                continue;

            if (dist_j[curx][cury] + 1 >= dist_f[nx][ny] && dist_f[nx][ny] != -1)
                continue;
            q_j.push({nx, ny});
            dist_j[nx][ny] = dist_j[curx][cury] + 1;
        }
        if (flag)
            break;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> mp[i];
        for (int j = 0; j < c; j++)
        {
            dist_f[i][j] = -1;
            dist_j[i][j] = -1;
            if (mp[i][j] == 'J')
            {
                q_j.push({i, j});
                dist_j[i][j] = 0;
            }
            if (mp[i][j] == 'F')
            {
                q_f.push({i, j});
                dist_f[i][j] = 0;
            }
        }
    }
    bfs();
    if (!flag)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << answer << endl;
    return 0;
}