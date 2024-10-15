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

#define endl "\n"
#define MAX 1000 + 10
#define INF 2100000000

int n, m, answer;
int mp[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    visited[x][y] = 1;
    int nx = x + dx[mp[x][y]];
    int ny = y + dy[mp[x][y]];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        return;

    if (visited[nx][ny] == 0)
        dfs(nx, ny);
    if (visited[nx][ny] == 1)
        answer++;
    visited[x][y] = 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == 'D')
                mp[i][j] = 3;
            else if (str[j] == 'U')
                mp[i][j] = 2;
            else if (str[j] == 'L')
                mp[i][j] = 1;
            else
                mp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0)
            {
                dfs(i, j);
            }
        }
    }
    cout << answer << endl;
    return 0;
}