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

#define MAX 1000 + 10
#define INF 987654321

int n, w;
double m;

struct Node
{
    int n;
    double cost;
};
struct cmp
{
    bool operator()(const Node a, const Node b)
    {
        return a.cost > b.cost;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w;
    cin >> m;

    int locX[n + 1];
    int locY[n + 1];
    double nodes[n + 1][n + 1];
    double dp[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        locX[i] = x;
        locY[i] = y;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INF;
        for (int j = 1; j <= n; j++)
        {
            double x = (locX[i] - locX[j]);
            double y = (locY[i] - locY[j]);

            double dist = sqrt(x * x + y * y);
            if (dist <= m)
            {
                nodes[i][j] = dist;
            }
            else
                nodes[i][j] = INF;
        }
    }

    for (int i = 0; i < w; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x][y] = 0;
        nodes[y][x] = 0;
    }
    priority_queue<Node, vector<Node>, cmp> pq;

    pq.push({1, 0.0});
    dp[1] = 0;
    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        if (dp[cur.n] != cur.cost)
            continue;

        if (cur.n == n)
            break;

        for (int i = 1; i <= n; i++)
        {
            if (nodes[cur.n][i] == INF)
                continue;

            double nxcost = cur.cost + nodes[cur.n][i];

            if (dp[i] > nxcost)
            {
                dp[i] = nxcost;
                pq.push({i, nxcost});
            }
        }
    }
    cout << (long long)(floor(dp[n] * 1000)) << endl;
    return 0;
}