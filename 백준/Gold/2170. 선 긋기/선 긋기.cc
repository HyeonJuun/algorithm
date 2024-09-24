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

#define MAX 1000000 + 10
#define INF 987654321

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v;

    int a, b;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int answer = 0;

    int st = v[0].first, ed = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (ed < v[i].first)
        {
            answer += ed - st;
            // cout << st << " " << ed << endl;
            st = v[i].first;
            ed = v[i].second;
        }
        if (v[i].second > ed)
        {
            ed = v[i].second;
        }
        // cout << "i : " << i << " st : " << st << " ed : " << ed << endl;
    }
    answer += ed - st;
    cout << answer << endl;
    return 0;
}