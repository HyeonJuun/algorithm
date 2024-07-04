#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 200000 + 10

int n, m;
int a, b, c;
long long answer;
int par[MAX];
vector<pair<int, pair<int, int>>> v;

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
    for (int i = 0; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        v.push_back({t, {0, i}});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        int a = find(v[i].second.first);
        int b = find(v[i].second.second);
        int cost = v[i].first;
        if (a != b)
        {
            union_(a, b);
            answer += cost;
        }
    }
    cout << answer << endl;
    return 0;
}