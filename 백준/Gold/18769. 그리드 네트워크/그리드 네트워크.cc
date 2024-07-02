#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 250000 + 10

int tc, r, c;
int a, b, x, answer;
int par[MAX];
vector<pair<int, pair<int, int>>> v;

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void union_(int a, int b)
{
    int para = find(a);
    int parb = find(b);

    par[parb] = para;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;

    while (tc--)
    {
        cin >> r >> c;
        answer = 0;
        v.clear();
        for (int i = 0; i < r * c; i++)
        {
            par[i] = i;
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c - 1; j++)
            {
                int a = i * c + j;
                int b = a + 1;
                cin >> x;
                v.push_back({x, {a, b}});
            }
        }
        for (int i = 0; i < r - 1; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int a = i * c + j;
                int b = ((i + 1) * c) + j;
                cin >> x;
                v.push_back({x, {a, b}});
            }
        }

        sort(v.begin(), v.end());

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
    }
    return 0;
}