#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int t, a, b;

bool visited[100000];

void bfs()
{
    queue < pair<int, string>> q;
    visited[a] = true;
    q.push({ a, "" });

    while (!q.empty())
    {
        int cur = q.front().first;
        string str = q.front().second;
        q.pop();

        if (cur == b)
        {
            cout << str << '\n';
            return;
        }
        int nxt = (cur * 2) % 10000;
        if (!visited[nxt])
        {
            visited[nxt] = true;
            q.push({ nxt, str + "D" });
        }
        if (cur - 1 < 0)
            nxt = 9999;
        else
            nxt = cur - 1;
        if (!visited[nxt])
        {
            visited[nxt] = true;
            q.push({ nxt, str + "S" });
        }
        nxt = (cur % 1000) * 10 + (cur / 1000);
        if (!visited[nxt])
        {
            visited[cur] = true;
            q.push({ nxt, str + "L" });
        }
        nxt = cur / 10 + (cur % 10) * 1000;
        if (!visited[nxt])
        {
            visited[nxt] = true;
            q.push({ nxt, str + "R" });
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        memset(visited, false, sizeof(visited));
        cin >> a >> b;
        bfs();
    }
}