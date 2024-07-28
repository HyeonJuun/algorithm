#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 100 + 10
#define INF 987654321

int t, n, m, k, answer;
int a, b, c;
int mp[MAX][MAX];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (i == j)
                    mp[i][j] = 0;
                else
                    mp[i][j] = INF;
            }
        }
        v.clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            mp[a][b] = c;
            mp[b][a] = c;
        }

        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                        continue;
                    if (mp[i][j] >= mp[i][k] + mp[k][j])
                    {
                        mp[i][j] = mp[i][k] + mp[k][j];
                    }
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << mp[i][j] << " ";
        //     cout << endl;
        // }
        answer = 0;
        int mn = INF;
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int j = 0; j < v.size(); j++)
            {
                sum += mp[i][v[j]];
            }
            if (mn > sum)
            {
                mn = sum;
                answer = i;
            }
        }
        cout << answer << endl;
    }
    return 0;
}