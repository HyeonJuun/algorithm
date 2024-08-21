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

#define MAX 10 + 1
#define INF 987654321

int n, m, l, answer;
vector<int> v;

bool solve(long long num)
{
    if (num == 0)
        return false;
    int res = 0;
    for (int i = 1; i < v.size(); i++)
    {
        int dist = v[i] - v[i - 1];
        if (dist > num)
        {
            if (dist % num == 0)
                res += (dist / num) - 1;
            else
                res += (dist / num);
            // res += dist % num != 0 ? dist / num : (dist / num) - 1;
        }
    }
    return res <= m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> l;
    v.push_back(0);
    v.push_back(l);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int le = 1, ri = l * 2;

    while (le <= ri)
    {
        int mid = (le + ri) / 2;

        if (solve(mid))
        {
            answer = mid;
            ri = mid - 1;
        }
        else
            le = mid + 1;
    }
    cout << answer << endl;
    return 0;
}