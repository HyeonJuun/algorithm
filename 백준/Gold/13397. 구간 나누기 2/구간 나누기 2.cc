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

#define MAX 10000
#define INF 987654321

int n, m;
vector<int> v;
int answer = INF;
bool solve(int num)
{
    int res = 1;
    int mx = v[0], mn = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);

        if (mx - mn > num)
        {
            res++;
            mx = v[i];
            mn = v[i];
        }
    }
    return res <= m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int l = 0;
    int r = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

    answer = r;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}