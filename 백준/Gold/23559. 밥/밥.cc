#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 30 + 1

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - a.second) > abs(b.first - b.second);
}
int main()
{
    int n, x;
    cin >> n >> x;
    v.resize(n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
        x -= 1000;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        if (x >= 4000 && v[i].first - v[i].second >= 0)
        {
            x -= 4000;
            sum += v[i].first - v[i].second;
        }
    }
    cout << sum << endl;
}