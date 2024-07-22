#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 500000 + 10

int n, m, a, b;
int par[MAX];
int answer;
int find(int x)
{
    if (x == par[x])
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
        cin >> a >> b;

        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
        {
            answer = i + 1;
            break;
        }
        else
        {
            union_(pa, pb);
        }
    }
    cout << answer << endl;
    return 0;
}