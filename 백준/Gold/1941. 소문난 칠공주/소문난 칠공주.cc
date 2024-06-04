#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 5 + 1

using namespace std;

int answer;
int map[5][5];
bool visited[25];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool is_answer()
{
    queue<pair<int, int>> q;
    bool ck_visited[5][5];
    bool q_visited[5][5];
    bool flag = false;

    memset(ck_visited, false, sizeof(ck_visited));
    memset(q_visited, false, sizeof(q_visited));

    int tmp = 0;
    for (int i = 0; i < 25; i++)
    {
        if (visited[i])
        {
            int x = i / 5;
            int y = i % 5;
            ck_visited[x][y] = true;

            if (tmp == 0)
            {
                q.push({x, y});
                q_visited[x][y] = true;
                tmp++;
            }
        }
    }
    int cnt = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (cnt == 7)
        {
            flag = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;

            if (ck_visited[nx][ny] && !q_visited[nx][ny])
            {
                q.push({nx, ny});
                q_visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    if (flag)
        return true;
    else
        return false;
}
bool ck_sCnt()
{
    int cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (visited[i] == true)
        {
            int x = i / 5;
            int y = i % 5;

            if (map[x][y] == 2)
                cnt++;
        }
    }
    if (cnt >= 4)
        return true;
    else
        return false;
}
void dfs(int idx, int dep)
{
    if (dep == 7)
    {
        if (ck_sCnt())
        {
            if (is_answer())
            {
                answer++;
            }
        }
        return;
    }
    for (int i = idx; i < 25; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i, dep + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++)
        {
            if (str[j] == 'Y')
                map[i][j] = 1;
            else
                map[i][j] = 2;
        }
    }
    dfs(0, 0);
    cout << answer << endl;
    return 0;
}