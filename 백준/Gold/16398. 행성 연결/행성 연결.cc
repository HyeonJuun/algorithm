#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000 + 10

int n;
int par[MAX];
int mp[MAX][MAX];
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
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == j)
                continue;
            v.push_back({mp[i][j], {i, j}});
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        par[i] = i;

    for (int i = 0; i < v.size(); i++)
    {
        int a = find(v[i].second.first);
        int b = find(v[i].second.second);
        int cost = v[i].first;

        if (a != b)
        {
            answer += cost;
            union_(a, b);
        }
    }
    cout << answer << endl;
    return 0;
}