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

#define MAX 500 + 10
#define INF 987654321

int n, l;
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int answer = 0, cur = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int st = v[i].first;
        int ed = v[i].second;

        if (cur > st)
            st = cur;
        if (cur > ed)
            ed = cur;

        if (ed - st > l)
        {
            if ((ed - st) % l == 0)
            {
                answer += (ed - st) / l;
                cur = ed;
            }
            else
            {
                answer += ((ed - st) / l) + 1;
                cur = st + l * (((ed - st) / l) + 1);
            }
        }
        else if (ed - st == 0)
        {
            continue;
        }
        else
        {
            cur = st + l;
            answer++;
        }
        // cout << "st : " << st << " ed : " << ed << endl
        //      << " cur : " << cur << " answer << " << answer << endl;
    }
    cout << answer << endl;
    return 0;
}