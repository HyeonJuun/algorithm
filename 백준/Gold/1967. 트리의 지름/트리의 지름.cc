#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define endl "\n"
#define MAX 10000 + 10
#define INF 2100000000

int n;
int a, b, c;
vector<pair<int, int>> v[MAX];
bool visited[MAX];
int answer, endpoint;

void dfs(int cur, int len)
{

    visited[cur] = true;

    if (answer < len)
    {
        answer = len;
        endpoint = cur;
    }
    for (int i = 0; i < v[cur].size(); i++)
    {
        int nx = v[cur][i].first;
        int cost = v[cur][i].second;

        if (!visited[nx])
        {
            dfs(nx, len + cost);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, 0);
    answer = 0;
    memset(visited, false, sizeof(visited));

    dfs(endpoint, 0);

    cout << answer << endl;
    return 0;
}