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

#define MAX 1000 + 10
#define INF 987654321

int tc, h, w, answer;

string mp[MAX];
int dist1[MAX][MAX];
int dist2[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {
        cin >> w >> h;
        queue<pair<int, int>> fire;
        queue<pair<int, int>> sang;
        bool flag = false;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                dist1[i][j] = -1;
                dist2[i][j] = -1;
            }
        }
        for (int i = 0; i < h; i++)
            cin >> mp[i];

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (mp[i][j] == '*')
                {
                    fire.push({i, j});
                    dist1[i][j] = 0;
                }
                if (mp[i][j] == '@')
                {
                    sang.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }

        while (!fire.empty())
        {
            int x = fire.front().first;
            int y = fire.front().second;
            fire.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                    continue;

                if (dist1[nx][ny] >= 0 || mp[nx][ny] == '#')
                    continue;

                dist1[nx][ny] = dist1[x][y] + 1;
                fire.push({nx, ny});
            }
        }
        while (!sang.empty())
        {
            int x = sang.front().first;
            int y = sang.front().second;
            sang.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    answer = dist2[x][y] + 1;
                    flag = true;
                    break;
                }
                if (dist2[nx][ny] >= 0 || mp[nx][ny] == '#')
                    continue;
                if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1)
                    continue;

                dist2[nx][ny] = dist2[x][y] + 1;
                sang.push({nx, ny});
            }
            if (flag)
                break;
        }
        if (flag)
            cout << answer << endl;
        else
            cout << "IMPOSSIBLE" << endl;

        for (int i = 0; i < h; i++)
            mp[i] = "";
    }
    return 0;
}