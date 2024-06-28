#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 100000 + 10

int n, m;
int par[MAX];
vector<pair<int, pair<int, int>>> graph;
vector<int> dist;
int a, b, c, answer;

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
void union_(int a, int b)
{
    a = find(a);
    b = find(b);

    par[b] = a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
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
            dist.push_back(cost);
        }
    }
    for (int i = 0; i < dist.size() - 1; i++)
    {
        answer += dist[i];
    }
    cout << answer << endl;
    return 0;
}