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
#define MAX 100000 + 10
#define INF 2100000000

int p, g;
int par[MAX];

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
void uni(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if (pa > pb)
        swap(pa, pb);

    par[pb] = pa;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    cin >> g >> p;
    for (int i = 0; i <= g; i++)
        par[i] = i;

    while (p--)
    {
        int x;
        cin >> x;

        int px = find(x);
        if (px == 0)
            break;
        else
        {
            answer++;
            uni(px, px - 1);
        }
    }
    cout << answer << endl;
    return 0;
}