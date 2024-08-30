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

int n, m;
int a, b, x, y;
bool on[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> v[MAX][MAX];
int answer;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    on[x][y] = true;
    answer++;

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < v[curx][cury].size(); i++)
        {
            int roomX = v[curx][cury][i].first;
            int roomY = v[curx][cury][i].second;

            if (!on[roomX][roomY])
            {
                answer++;
                on[roomX][roomY] = true;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = roomX + dx[dir];
                    int ny = roomY + dy[dir];

                    if (nx < 1 || ny < 1 || nx > n || ny > n)
                        continue;
                    if (visited[nx][ny])
                    {
                        q.push({roomX, roomY});
                        visited[roomX][roomY] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n || !on[nx][ny])
                continue;

            if (!visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
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
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> a >> b;
        v[x][y].push_back({a, b});
    }
    // cout << endl;
    solve(1, 1);
    cout << answer << endl;
    return 0;
}