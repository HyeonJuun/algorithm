#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#define MAX 1000 + 10
#define INF 2e9
using namespace std;

int n, m;
int a, b, c;
vector<pair<int, pair<int, int>>> graph;
int par[MAX];
int st_pos, tar_pos;
long long mx, mn;

bool cmp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first < b.first;
}
bool cmp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.first > b.first;
}
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
void uni(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    par[pb] = pa;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m + 1; i++)
    {
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end(), cmp1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < graph.size(); i++)
    {
        st_pos = find(graph[i].second.first);
        tar_pos = find(graph[i].second.second);
        if (st_pos != tar_pos)
        {
            uni(st_pos, tar_pos);
            if (!graph[i].first)
                mn++;
        }
    }
    sort(graph.begin(), graph.end(), cmp2);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < graph.size(); i++)
    {
        st_pos = find(graph[i].second.first);
        tar_pos = find(graph[i].second.second);
        if (st_pos != tar_pos)
        {
            uni(st_pos, tar_pos);
            if (!graph[i].first)
                mx++;
        }
    }
    cout << mn * mn - mx * mx << endl;
    return 0;
}