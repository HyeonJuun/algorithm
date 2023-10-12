#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2e8;
int n, m;
int a, b, c;

int map[110][110];

int dist[110][110];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1 ,0 ,0 };
bool isValid(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
    
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    priority_queue < pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
        }
    }
    dist[0][0] = 0;
    pq.push({ 0, {0, 0} });
    
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[x][y] != cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny))
                continue;
       
            int nd = cost + map[nx][ny];

            if (nd >= dist[nx][ny])
                continue;
            
            pq.push({ nd, {nx, ny} });
            dist[nx][ny] = nd;
        }
    }
    cout << dist[n - 1][m - 1] << endl;
    return 0;
}
