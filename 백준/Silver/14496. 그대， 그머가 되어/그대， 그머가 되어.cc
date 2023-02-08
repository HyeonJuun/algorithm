#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b;
int n, m;
int x1, x2;
vector<int> v[1010];
bool visited[1010];

int main() {

    cin >> a >> b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }
    queue<pair<int, int>> q;
    q.push({ a, 0 });
    visited[a] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (x == b)
        {
            cout << dist;
            return 0;
        }
        for (int i = 0; i < v[x].size(); i++)
        {
            int nxt = v[x][i];
            if (!visited[nxt])
            {
                q.push({ nxt, dist + 1 });
                visited[nxt] = true;
            }
        }
    }

    cout << -1;
    return 0;

}