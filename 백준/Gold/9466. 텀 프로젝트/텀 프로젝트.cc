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

#define MAX 100000 + 10
#define INF 2100000000

int t, n, res;
vector<int> v;
bool visited[MAX];
bool done[MAX];
int cnt;
void solve(int cur)
{
    visited[cur] = true;
    int nx = v[cur];

    if (!visited[nx])
    {
        solve(nx);
    }
    else if (!done[nx])
    {
        for (int i = nx; i != cur; i = v[i])
        {
            cnt++;
        }
        cnt++;
    }
    done[cur] = true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        v.clear();
        v.resize(n + 1);
        cnt = 0;
        memset(visited, false, n + 1);
        memset(done, false, n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                solve(i);
            }
        }
        cout << n - cnt << endl;
    }
    return 0;
}