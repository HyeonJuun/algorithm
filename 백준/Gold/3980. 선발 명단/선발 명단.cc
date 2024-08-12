#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

int c;
int arr[20][20];
int mx = -1;
bool visited[20];
int answer[20];

void solve(int cur, int sum)
{
    if (cur == 11)
    {
        mx = max(mx, sum);
        return;
    }
    for (int i = 0; i < 11; i++)
    {
        if (arr[i][cur] == 0)
            continue;
        if (!visited[i])
        {
            visited[i] = true;
            solve(cur + 1, sum + arr[i][cur]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> c;
    while (c--)
    {
        memset(visited, false, sizeof(visited));
        mx = 0;
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                cin >> arr[i][j];
            }
        }

        solve(0, 0);
        cout << mx << endl;
    }
    return 0;
}