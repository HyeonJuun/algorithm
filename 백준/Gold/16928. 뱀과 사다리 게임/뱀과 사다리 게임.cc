#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m, x, y;

int cnt = 0;
int map[101];
bool visited[101];

void bfs(int num)
{
    queue<pair<int, int>> q;
    q.push({ num, 0 });
    
    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nxt = cur + i;
            if (nxt == 100)
            {
                cout << cnt + 1;
                return;
            }
            else if (nxt < 100)
            {
                while (map[nxt] != 0)
                {
                    nxt = map[nxt];
                }
                if (!visited[nxt])
                {
                    q.push({ nxt, cnt + 1 });
                    visited[nxt] = true;
                }
            }
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        map[x] = y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        map[x] = y;
    }
    bfs(1);
    return 0;
}