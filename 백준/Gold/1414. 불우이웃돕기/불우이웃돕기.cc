#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000 + 10

int n, cnt;
vector<pair<int, pair<int, int>>> v;
long long total, sum;
int mp[MAX][MAX];
int par[MAX];
string str;

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
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '0')
                continue;

            if ('a' <= str[j] && str[j] <= 'z')
                mp[i][j] = str[j] - 97 + 1;
            else if ('A' <= str[j] && str[j] <= 'Z')
                mp[i][j] = str[j] - 65 + 27;
            total += mp[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || mp[i][j] == 0)
                continue;
            v.push_back({mp[i][j], {i, j}});
        }
        par[i] = i;
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
            sum += cost;
            cnt++;
        }
    }
    if (cnt < n - 1)
        cout << -1 << endl;
    else
        cout << total - sum << endl;
    return 0;
}