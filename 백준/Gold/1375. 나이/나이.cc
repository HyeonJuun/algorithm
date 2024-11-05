#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m, peo_cnt;
vector<int> edge[1000003];
unordered_map<string, int> mp;

void name_update(string &s)
{
    if (mp.find(s) == mp.end())
        mp[s] = peo_cnt++;
}

bool bfs(int cur, int tar)
{
    bool vst[1000003] = {
        0,
    };
    queue<int> q;
    q.push(cur);
    vst[cur] = 1;
    while (!q.empty())
    {
        int cur_idx = q.front();
        q.pop();
        if (cur_idx == tar)
            return true;

        for (int nxt : edge[cur_idx])
            if (!vst[nxt])
            {
                q.push(nxt);
                vst[nxt] = 1;
            }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        string a, b;
        cin >> a >> b;
        name_update(a);
        name_update(b);
        edge[mp[a]].push_back(mp[b]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        string a, b;
        cin >> a >> b;
        name_update(a);
        name_update(b);
        int aIdx = mp[a], bIdx = mp[b];
        if (aIdx == bIdx)
        {
            cout << "gg ";
            continue;
        }

        if (bfs(aIdx, bIdx))
            cout << a << ' ';
        else if (bfs(bIdx, aIdx))
            cout << b << ' ';
        else
            cout << "gg ";
    }
}