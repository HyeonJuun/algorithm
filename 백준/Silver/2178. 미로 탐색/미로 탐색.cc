#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100 + 1

using namespace std;

int n, m, answer;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if (curx == n - 1 && cury == m - 1)
        {
            cout << cost << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '0')
                continue;

            if (!visited[nx][ny])
            {
                q.push({{nx, ny}, cost + 1});
                visited[nx][ny] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    solve();

    return 0;
}