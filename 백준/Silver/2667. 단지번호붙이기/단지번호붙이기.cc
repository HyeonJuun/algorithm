#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100 + 1

using namespace std;

int n;
vector<int> answer;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int solve(int x, int y)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    // cout << "x : " << x << " y : " << y << endl;
    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == 0)
                continue;

            if (!visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    cin >> n;
    int land_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = str[j] - '0';
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
            {
                int x = solve(i, j);
                answer.push_back(x);
                land_cnt++;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << land_cnt << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}