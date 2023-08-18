#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


bool visited[101];
int map[101][101];

int main()
{
    int n, m;
    int answer = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && map[cur][i])
            {
                q.push(i);
                visited[i] = true;
                answer++;
            }
        }
    }
    cout << answer << endl;


}
