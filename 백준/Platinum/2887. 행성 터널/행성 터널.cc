#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100000 + 10

int n;
int x, y, z;
long long answer;
int par[MAX];
vector<pair<int, pair<int, int>>> planet;
vector<pair<int, int>> v[3];

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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        v[0].push_back({x, i});
        v[1].push_back({y, i});
        v[2].push_back({z, i});
        par[i] = i;
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());

    for (int i = 0; i < n - 1; i++)
    {
        planet.push_back(make_pair(abs(v[0][i].first - v[0][i + 1].first), make_pair(v[0][i].second, v[0][i + 1].second)));
        planet.push_back(make_pair(abs(v[1][i].first - v[1][i + 1].first), make_pair(v[1][i].second, v[1][i + 1].second)));
        planet.push_back(make_pair(abs(v[2][i].first - v[2][i + 1].first), make_pair(v[2][i].second, v[2][i + 1].second)));
    }
    sort(planet.begin(), planet.end());
    for (int i = 0; i < planet.size(); i++)
    {
        int a = find(planet[i].second.first);
        int b = find(planet[i].second.second);
        int cost = planet[i].first;

        if (a != b)
        {
            union_(a, b);
            answer += cost;
        }
    }
    cout << answer << endl;
    return 0;
}