#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100000 + 1

using namespace std;
struct edge
{
    int st, ed, cost;
};
int n, m;
long long total, answer;
int a, b, c;

vector<edge> v;
int par[MAX];

bool comp(edge a, edge b)
{
    return a.cost < b.cost;
}
int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
void Union(int a, int b)
{
    int parA = find(a);
    int parB = find(b);

    if (parA < parB)
    {
        par[parB] = parA;
    }
    else
    {
        par[parA] = parB;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.push_back({a, b, c});
        total += c;
    }

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        int s = v[i].st;
        int e = v[i].ed;
        int c = v[i].cost;

        if (find(s) != find(e))
        {
            Union(s, e);
            answer += c;
        }
    }
    bool flag = false;
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != find(1))
        {
            flag = true;
            break;
        }
    }
    if (flag)
        answer = -1;
    else
        answer = total - answer;

    cout << answer << endl;
    return 0;
}