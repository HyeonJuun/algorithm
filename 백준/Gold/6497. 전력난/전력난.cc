#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 200010

int n, m, total, answer, result, x, y;
int par[MAX];
bool flag;
vector<pair<int, pair<int, int>>> graph;

int findPar(int a)
{
    if (a == par[a])
        return a;
    else
        return par[a] = findPar(par[a]);
}
bool ck(int a, int b)
{
    a = findPar(a);
    b = findPar(b);

    if (a == b)
        return true;
    else
        return false;
}
void uni(int a, int b)
{
    a = findPar(a);
    b = findPar(b);

    par[b] = a;
}
void solve()
{
    sort(graph.begin(), graph.end());
    for (int i = 0; i < graph.size(); i++)
    {
        int cost = graph[i].first;
        int nodeX = graph[i].second.first;
        int nodeY = graph[i].second.second;

        if (ck(nodeX, nodeY) == false)
        {
            uni(nodeX, nodeY);
            result += cost;
        }
    }
    answer = total - result;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        graph.clear();
        total = 0;
        result = 0;
        for (int i = 0; i < MAX; i++)
        {
            par[i] = i;
        }
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph.push_back({c, {a, b}});
            total += c;
        }
        solve();
        cout << answer << endl;
    }

    return 0;
}