#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100001

using namespace std;

int n, k;
bool answer;
int map[2][MAX];
bool visited[2][MAX];
string str;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curt = q.front().second;
        q.pop();

        if (curt >= n)
        {
            break;
        }
        for (int i = 0; i < 2; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (ny >= n)
                answer = true;
            if (nx >= 0 && ny > curt && nx < 2 && ny < n)
            {
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, curt + 1});
                }
            }
        }
        for (int i = 2; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i] + k;

            if (ny >= n)
                answer = true;

            if (nx >= 0 && ny > curt && nx < 2 && ny < n)
            {
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, curt + 1});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < 2; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            map[i][j] = str[j] - '0';
        }
    }
    solve();
    if (answer)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}