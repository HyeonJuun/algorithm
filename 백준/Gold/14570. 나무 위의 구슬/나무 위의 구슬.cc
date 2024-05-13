#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define MAX 200000 + 1

struct c
{
    int left;
    int right;
};

vector<c> graph;
int n, u, v, answer;
long long k;
void solve(int cur, long long k)
{
    if (graph[cur].left == -1 && graph[cur].right == -1)
    {
        answer = cur;
        return;
    }
    else if (graph[cur].left == -1)
    {
        solve(graph[cur].right, k);
    }
    else if (graph[cur].right == -1)
    {
        solve(graph[cur].left, k);
    }
    else if (k % 2 != 0)
    {
        solve(graph[cur].left, k / 2 + 1);
    }
    else
    {
        solve(graph[cur].right, k / 2);
    }
    return;
}
int main()
{
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        graph[i].left = u;
        graph[i].right = v;
    }

    cin >> k;
    solve(1, k);

    cout << answer << endl;
}
