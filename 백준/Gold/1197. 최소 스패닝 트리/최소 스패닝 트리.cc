#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10000 + 10

int v, e;
int a, b, c;
long long answer;
vector<pair<int, pair<int, int>>> graph;
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
    a = find(a);
    b = find(b);

    par[b] = a;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }

    sort(graph.begin(), graph.end());
    for (int i = 0; i <= v; i++)
        par[i] = i;

    for (int i = 0; i < graph.size(); i++)
    {
        int a = find(graph[i].second.first);
        int b = find(graph[i].second.second);
        int cost = graph[i].first;

        if (a != b)
        {
            union_(a, b);
            answer += cost;
        }
    }
    cout << answer << endl;
    return 0;
}