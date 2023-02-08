#include <iostream>
#include <queue>

using namespace std;

int a , k;
queue<pair<int, int>> q;
bool visited[2000010];
int main() {

    cin >> a >> k;

    q.push({ a, 0 });
    visited[1] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (cur == k)
        {
            cout << dist;
            break;
        }
        if (cur > 1000000)
            continue;
        if (!visited[cur * 2])
        {
            q.push({ cur * 2, dist + 1 });
            visited[cur * 2] = true;
        }
        if (!visited[cur + 1])
        {
            q.push({ cur + 1, dist + 1 });
            visited[cur + 1] = true;
        }
    }
    return 0;
}