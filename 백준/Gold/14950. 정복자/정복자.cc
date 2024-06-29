#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10000 + 10

int n, m, t;
int par[MAX];
vector<pair<int, pair<int, int>>> v;
int a, b, c;
long long int answer;

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
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        par[i] = i;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int a = find(v[i].second.first);
        int b = find(v[i].second.second);
        int cost = v[i].first + count * t;

        if (a != b)
        {
            answer += cost;
            count++;
            union_(a, b);
        }
    }
    cout << answer << endl;
    return 0;
}