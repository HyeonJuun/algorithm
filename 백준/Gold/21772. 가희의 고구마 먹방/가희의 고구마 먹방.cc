#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 100 + 10
#define INF 987654321

int mp[MAX][MAX];
int dx[] = {0, 0, -1, 1, 0};
int dy[] = {1, -1, 0, 0, 0};

int r, c, t, answer = 0;
int sx, sy;
void solve(int x, int y, int cnt, int ans)
{
    if (cnt >= t)
    {
        answer = max(answer, ans);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c || mp[nx][ny] == -1)
            continue;
        if (mp[nx][ny] == 1)
        {
            mp[nx][ny] = 0;
            solve(nx, ny, cnt + 1, ans + 1);
            mp[nx][ny] = 1;
        }
        else
            solve(nx, ny, cnt + 1, ans);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
                mp[i][j] = 0;
            else if (x == '#')
                mp[i][j] = -1;
            else if (x == 'G')
            {
                mp[i][j] = 0;
                sx = i;
                sy = j;
            }
            else if (x == 'S')
            {
                mp[i][j] = 1;
            }
        }
    }
    solve(sx, sy, 0, 0);
    cout << answer << endl;
    return 0;
}