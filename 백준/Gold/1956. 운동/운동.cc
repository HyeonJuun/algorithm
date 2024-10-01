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

#define MAX 400 + 10
#define INF 987654321

int v, e, a, b, c;
int mp[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            mp[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        mp[a][b] = c;
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (mp[i][j] > mp[i][k] + mp[k][j])
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                }
            }
        }
    }
    int answer = INF;
    for (int i = 1; i <= v; i++)
    {
        answer = min(answer, mp[i][i]);
    }
    if (answer == INF)
        answer = -1;
    cout << answer << '\n';
    return 0;
}