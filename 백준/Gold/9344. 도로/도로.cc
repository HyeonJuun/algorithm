#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 10000 + 10

int t, n, m, p, q;
int u, v, w;
vector<pair<int, pair<int, int>>> graph;
vector<pair<int, int>> roads;
int par[MAX];

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void union_(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    par[pb] = pa;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> p >> q;
        for (int i = 0; i <= n; i++)
            par[i] = i;
        graph.clear();
        roads.clear();

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            graph.push_back({w, {u, v}});
        }
        sort(graph.begin(), graph.end());
        for (int i = 0; i < graph.size(); i++)
        {
            int a = find(graph[i].second.first);
            int b = find(graph[i].second.second);
            int cost = graph[i].first;

            if (a != b)
            {
                union_(a, b);
                roads.push_back({graph[i].second.first, graph[i].second.second});
            }
        }
        bool answer = false;
        for (int i = 0; i < roads.size(); i++)
        {
            if ((roads[i].first == p && roads[i].second == q) || (roads[i].first == q && roads[i].second == p))
            {
                answer = true;
                break;
            }
        }

        if (answer)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}