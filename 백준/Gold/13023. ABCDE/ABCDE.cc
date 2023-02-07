#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
vector<int> v[2010];
bool visited[2010];
bool flag = false;

void dfs(int cur, int dep)
{
    if (dep == 4)
    {
        flag = true;
        return;
    }

    for (int i = 0; i < v[cur].size(); i++)
    {
        int nxt = v[cur][i];
        if (!visited[nxt])
        {
            visited[nxt] = true;
            dfs(nxt, dep + 1);
            visited[nxt] = false;
        }
    }
}
int main() {
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        dfs(i, 0);
        if (flag)
        {
            break;
        }
    }

    cout << flag;
    return 0;
}