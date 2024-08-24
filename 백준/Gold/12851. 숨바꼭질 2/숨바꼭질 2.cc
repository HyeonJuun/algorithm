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

#define MAX 100000 + 10
#define INF 987654321

int n, k;

queue<pair<int, int>> q;
bool first = true;
int visited[MAX];
int res1 = MAX, res2 = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    q.push({n, 0});
    visited[n] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        visited[cur] = true;

        if (!first && res1 == cnt && cur == k)
        {
            res2++;
        }

        if (first && cur == k)
        {
            res1 = cnt;
            first = false;
            res2++;
        }

        if (cur + 1 < MAX && cur + 1 >= 0 && !visited[cur + 1])
        {
            q.push({cur + 1, cnt + 1});
        }
        if (cur - 1 < MAX && cur - 1 >= 0 && !visited[cur - 1])
        {
            q.push({cur - 1, cnt + 1});
        }
        if (cur * 2 < MAX && cur * 2 >= 0 && !visited[cur * 2])
        {
            q.push({cur * 2, cnt + 1});
        }
    }
    cout << res1 << endl
         << res2 << endl;
    return 0;
}