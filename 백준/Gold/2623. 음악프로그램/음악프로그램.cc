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
#define MAX 1000 + 10
#define INF 2100000000

int n, m;
int entry[MAX];
vector<int> v[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        vector<int> tmp;
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        for (int j = 0; j < tmp.size(); j++)
        {
            for (int k = j + 1; k < tmp.size(); k++)
            {
                v[tmp[j]].push_back(tmp[k]);
                entry[tmp[k]]++;
            }
        }
    }
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (entry[i] == 0)
            q.push(i);
    }
    vector<int> answer;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nx = v[cur][i];
            entry[nx]--;

            if (entry[nx] == 0)
                q.push(nx);
        }
    }
    if (answer.size() != n)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << endl;
        }
    }

    return 0;
}