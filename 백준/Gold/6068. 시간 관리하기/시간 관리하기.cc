#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#define MAX 500 + 1
#define INF 2e9

using namespace std;

int n;
int a, b;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    int tmp = 0, start_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            if (v[i].second > tmp)
            {
                start_time += v[i].second - tmp;
            }
            else if (tmp - v[i].second >= start_time)
            {
                start_time = 0;
            }
            else if (tmp - v[i].second < start_time)
            {
                start_time -= tmp - v[i].second;
            }
        }
        tmp = v[i].second - v[i].first;
    }
    if (start_time > 0)
        tmp -= start_time;

    if (tmp < 0)
        cout << -1 << endl;
    else
        cout << tmp << endl;
    return 0;
}