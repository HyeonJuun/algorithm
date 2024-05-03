#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50 + 1;

// 문제
// 인체에 치명적인 바이러스를 연구하던 연구소에 승원이가 침입했고, 바이러스를 유출하려고 한다.
// 승원이는 연구소의 특정 위치에 바이러스 M개를 놓을 것이고, 승원이의 신호와 동시에 바이러스는 퍼지게 된다.
// 연구소는 크기가 N×N인 정사각형으로 나타낼 수 있으며, 정사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
// 일부 빈 칸은 바이러스를 놓을 수 있는 칸이다. 바이러스는 상하좌우로 인접한 모든 빈 칸으로 동시에 복제되며, 1초가 걸린다.
// 예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸이다.
// 연구소의 상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간을 구해보자.
// --------------------------------------------------------------------------------------------------------------
// 입력
// 첫째 줄에 연구소의 크기 N(5 ≤ N ≤ 50), 놓을 수 있는 바이러스의 개수 M(1 ≤ M ≤ 10)이 주어진다.
// 둘째 줄부터 N개의 줄에 연구소의 상태가 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸이다. 2의 개수는 M보다 크거나 같고, 10보다 작거나 같은 자연수이다.
// --------------------------------------------------------------------------------------------------------------
// 출력
// 연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다. 바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력한다
// --------------------------------------------------------------------------------------------------------------

int n, m, x, answer = 2e9;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool checked[MAX * MAX];
vector<pair<int, int>> v;
vector<pair<int, int>> selected;
queue<pair<int, int>> q;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int bfs()
{
    int dist[MAX][MAX];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = map[i][j];
            if (dist[i][j] == 2)
            {
                dist[i][j] = 0;
            }
            else if (dist[i][j] == 1)
            {
                dist[i][j] = -1;
            }
        }
    }
    queue<pair<int, int>> q;

    for (int i = 0; i < selected.size(); i++)
    {
        q.push({selected[i].first, selected[i].second});
        visited[selected[i].first][selected[i].second] = true;
    }

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || dist[nx][ny] == -1)
                continue;

            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[curx][cury] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == -1)
                continue;
            else
            {
                if (!visited[i][j])
                {
                    return 2e9;
                }
                else
                {
                    res = max(res, dist[i][j]);
                }
            }
        }
    }
    return res;
}
void solve(int dep, int cur)
{

    if (dep == m)
    {
        memset(visited, false, sizeof(visited));
        answer = min(answer, bfs());
        return;
    }
    for (int i = cur; i < v.size(); i++)
    {
        if (!checked[i])
        {
            checked[i] = true;
            selected.push_back({v[i].first, v[i].second});
            solve(dep + 1, i + 1);
            selected.pop_back();
            checked[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                v.push_back({i, j});
            }
        }
    }
    solve(0, 0);
    if (answer == 2e9)
    {
        answer = -1;
    }
    cout << answer << endl;
    return 0;
}
