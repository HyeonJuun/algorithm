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
#define MOD 1000000007
#define ll long long
#define pii pair<int, int>

int n, l, h, o;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pii a, pii b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> o;
        if (h > o)
            swap(h, o);
        v.push_back({h, o});
    }
    cin >> l;
    sort(v.begin(), v.end(), cmp);

    int res = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i].first;
        int end = v[i].second;

        if (end - start > l)
            continue;

        pq.push(start);

        while (!pq.empty())
        {
            if (pq.top() + l >= end)
            {
                res = max(res, (int)pq.size());
                break;
            }
            else
                pq.pop();
        }
    }
    cout << res << endl;
    return 0;
}