#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 2e8;
int n, m;
int s, e;

int answer;
vector<pair<int, int>> graph[100010];
bool visited[100010];

bool bfs(int weight)
{
    memset(visited, false, sizeof(visited));

    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == e)
            return true;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int nx = graph[cur][i].first;
            int w = graph[cur][i].second;
            if (w < weight || visited[nx])
                continue;

            q.push(nx);
            visited[nx] = true;
        }
    }
    return false;
}
int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    cin >> s >> e;

    int left = 0, right = 1000000000;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (bfs(mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << answer;
    return 0;
}
