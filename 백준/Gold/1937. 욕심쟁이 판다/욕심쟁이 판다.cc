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

#define MAX 500 + 10
#define INF 987654321

int n;
int arr[MAX][MAX];
int cost[MAX][MAX];
int answer;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int solve(int x, int y)
{
    int res = 1;

    if (cost[x][y] != -1)
        return cost[x][y];

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[x][y] >= arr[nx][ny])
            continue;

        res = max(res, solve(nx, ny) + 1);
    }
    return cost[x][y] = res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cost[i][j] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = solve(i, j);
            answer = max(answer, cost[i][j]);
        }
    }
    cout << answer << endl;
    return 0;
}