#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 2010;
const int INF = 2e9;

int T;
int n, m, t;
int s, g, h;
int a, b, d;
vector<pair<int, int>> graph[MAX];

vector<int> v;
int distS[MAX];
int distG[MAX];
int distH[MAX];

void memclear()
{
    
}
void dijkstra(int start, int dist[MAX])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> pq;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[cur] != cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int nxt = graph[cur][i].first;

            if (dist[nxt] > dist[cur] + graph[cur][i].second)
            {
                dist[nxt] = dist[cur] + graph[cur][i].second;
                pq.push({ dist[nxt], nxt });
            }
        }
    }
}
int main() {
    
    cin >> T;

    while (T--)
    {
        for (int i = 0; i < MAX; i++)
        {
            distS[i] = INF;
            distG[i] = INF;

            distH[i] = INF;
            graph[i].clear();
        }
        v.clear();
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            graph[a].push_back({ b, d });
            graph[b].push_back({ a, d });
        }
        for (int i = 0; i < t; i++)
        {
            int x;   cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);
        
        for (int i = 0; i < v.size(); i++)
        {
            int goal = v[i];
            
            if (distS[goal] == distS[g] + distG[h] + distH[goal])
                cout << goal << " ";
            else if(distS[goal] == distS[h] + distH[g] + distG[goal])
                cout << goal << " ";

        }
        cout << endl;
    }
    return 0;
}
