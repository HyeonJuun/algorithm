#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000 + 10

int n, m;
vector<pair<int, int>> v;
vector<pair<int, int>> connect;
vector<pair<double, pair<int, int>>> graph;
int par[MAX];
double answer;

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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        connect.push_back({a, b});
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            pair<int, int> a = v[i];
            pair<int, int> b = v[j];

            double len = (double)(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
            len = sqrt(len);
            graph.push_back({len, {i + 1, j + 1}});
        }
    }
    sort(graph.begin(), graph.end());
    for (int i = 1; i <= n; i++)
        par[i] = i;
    int cnt = 0;
    for (int i = 0; i < connect.size(); i++)
    {
        int a = connect[i].first;
        int b = connect[i].second;
        union_(a, b);
    }
    for (int i = 0; i < graph.size(); i++)
    {
        int a = find(graph[i].second.first);
        int b = find(graph[i].second.second);
        double cost = graph[i].first;

        if (a != b)
        {
            union_(a, b);
            answer += cost;
        }
    }
    printf("%.2f \n", answer);
    return 0;
}