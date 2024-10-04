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

#define MAX 200000 + 10
#define INF 2100000000

map<string, int> name;

int par[MAX];
int res[MAX];

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void uni(int a, int b)
{
    int pA = find(a);
    int pB = find(b);

    if (pB != pA)
    {
        par[pB] = pA;
        res[pA] += res[pB];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
        {
            par[i] = i;
            res[i] = 0;
        }
        name.clear();
        int idx = 1;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;

            if (name.find(a) == name.end())
            {
                res[idx] = 1;
                name[a] = idx++;
            }
            if (name.find(b) == name.end())
            {
                res[idx] = 1;
                name[b] = idx++;
            }
            uni(name[a], name[b]);

            cout << res[find(name[a])] << '\n';
        }
    }
    return 0;
}