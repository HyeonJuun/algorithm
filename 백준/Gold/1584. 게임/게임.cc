#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 5000 + 10
#define INF 987654321

int n, m;
int a, b, c, d;
int mp[501][501];
bool visited[501][501];
int answer;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve()
{
    deque<pair<int, pair<int, int>>> q;

    q.push_back({0, {0, 0}});
    visited[0][0] = true;

    while (!q.empty())
    {
        int curx = q.front().second.first;
        int cury = q.front().second.second;
        int cost = q.front().first;
        q.pop_front();

        if (curx == 500 && cury == 500)
        {
            answer = cost;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int ncost = cost;

            if (nx < 0 || ny < 0 || nx > 500 || ny > 500)
                continue;

            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                if (mp[nx][ny] == 1)
                {
                    ncost++;
                    q.push_back({ncost, {nx, ny}});
                }
                else
                {
                    q.push_front({ncost, {nx, ny}});
                }
            }
        }
    }
    answer = -1;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        if (a > c)
        {
            int tmp = a;
            a = c;
            c = tmp;
        }
        if (b > d)
        {
            int tmp = b;
            b = d;
            d = tmp;
        }
        for (int x = a; x <= c; x++)
        {
            for (int y = b; y <= d; y++)
            {
                mp[x][y] = 1;
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        if (a > c)
        {
            int tmp = a;
            a = c;
            c = tmp;
        }
        if (b > d)
        {
            int tmp = b;
            b = d;
            d = tmp;
        }
        for (int x = a; x <= c; x++)
        {
            for (int y = b; y <= d; y++)
            {
                visited[x][y] = true;
            }
        }
    }

    solve();

    cout << answer << endl;
    return 0;
}