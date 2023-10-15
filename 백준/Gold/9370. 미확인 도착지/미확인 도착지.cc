#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 2010;
const int INF = 2e9;
int T, n, m, t;
int s, g, h;
int a, b, d;
int x;

vector<pair<int, int>> graph[MAX];
vector<int> answer;
vector<int> Xvector;

int distS[MAX];
int distG[MAX];
int distH[MAX];

void Dijkstra(int start, int dist[MAX])
{
    priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;

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
            graph[i].clear();
            distS[i] = INF;
            distG[i] = INF;
            distH[i] = INF;
        }
        Xvector.clear();

        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++)
        {
            int a1, a2, a3;
            cin >> a1 >> a2 >> a3;
            graph[a1].push_back({ a2, a3 });
            graph[a2].push_back({ a1, a3 });
        }
        for (int i = 0; i < t; i++)
        {
            cin >> x;
            Xvector.push_back(x);
        }

        Dijkstra(s, distS);
        Dijkstra(g, distG);
        int distGH = distG[h];

        Dijkstra(h, distH);
        sort(Xvector.begin(), Xvector.end());

        for (int i = 0; i < Xvector.size(); i++)
        {
            int goal = Xvector[i];
            if (distS[goal] == distS[g] + distGH + distH[goal])
                cout << goal << " ";
            else if (distS[goal] == distS[h] + distGH + distG[goal])
                cout << goal << " ";
        }
        cout << endl;
    }
   
    return 0;
}
