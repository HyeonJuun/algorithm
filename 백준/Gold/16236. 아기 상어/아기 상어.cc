#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 20 + 1

using namespace std;

int n, answer;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int st_x, st_y, cnt, sz = 2;

int ck_dist(int sx, int sy, int ex, int ey)
{
    queue<pair<pair<int, int>, int>> q;
    memset(visited, false, sizeof(visited));
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;
    int res = 0;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        if (x == ex && y == ey)
        {
            return cost;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] > sz)
                continue;

            if (!visited[nx][ny])
            {
                q.push({{nx, ny}, cost + 1});
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}
pair<pair<int, int>, int> solve(int x, int y)
{
    pair<pair<int, int>, int> res = {{-1, -1}, 2e9};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] < sz && map[i][j] != 0)
            {
                int cost = ck_dist(x, y, i, j);
                if (cost < res.second && cost != -1)
                {
                    res.first.first = i;
                    res.first.second = j;
                    res.second = cost;
                }
            }
        }
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                st_x = i, st_y = j;
                map[i][j] = 0;
            }
        }
    }
    while (true)
    {
        auto ed = solve(st_x, st_y);
        if (ed.first.first == -1 || ed.first.second == -1 || ed.second == 2e9)
            break;
        // cout << "목적지 : " << ed.first.first << "  " << ed.first.second << " " << ed.second << endl;
        answer += ed.second;
        cnt++;
        if (cnt == sz)
        {
            cnt = 0, sz++;
        }
        map[ed.first.first][ed.first.second] = 0;
        st_x = ed.first.first;
        st_y = ed.first.second;
    }
    cout << answer << endl;
    return 0;
}