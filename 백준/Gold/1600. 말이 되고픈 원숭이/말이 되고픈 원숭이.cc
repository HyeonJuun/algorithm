#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 200 + 1

int dx[] = {-1, 1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2};

int mp[MAX][MAX];
bool visited[MAX][MAX][31];

int w, h, k, answer = 2e9;

using namespace std;

void solve()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    visited[0][0][0] = true;
    q.push({{0, 0}, {0, 0}});

    while (!q.empty())
    {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cost = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (curx == h - 1 && cury == w - 1)
        {
            answer = min(answer, cost);
            break;
        }
        if (cnt < k)
        {
            for (int i = 4; i < 12; i++)
            {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                    continue;

                if (!visited[nx][ny][cnt + 1] && mp[nx][ny] != 1)
                {
                    visited[nx][ny][cnt + 1] = true;
                    q.push({{nx, ny}, {cost + 1, cnt + 1}});
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w || mp[nx][ny] == 1)
                continue;

            if (!visited[nx][ny][cnt])
            {
                visited[nx][ny][cnt] = true;
                q.push({{nx, ny}, {cost + 1, cnt}});
            }
        }
    }
}
int main()
{
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> mp[i][j];
        }
    }

    solve();
    if (answer == 2e9)
        answer = -1;
    cout << answer << endl;
    return 0;
}