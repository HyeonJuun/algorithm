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

#define MAX 10 + 1
#define INF 987654321

int n, m;
int answer;
int arr[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX];

void solve(int cur, int dep, int sum)
{
    if (dep == n)
    {
        if (answer > sum)
            answer = sum;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == cur)
            continue;
        if (!visited[i])
        {
            visited[i] = true;
            solve(i, dep + 1, sum + arr[cur][i]);
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
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
            dist[i][j] = INF;
    }
    answer = INF;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    visited[m] = true;
    solve(m, 1, 0);
    cout << answer << endl;
    return 0;
}