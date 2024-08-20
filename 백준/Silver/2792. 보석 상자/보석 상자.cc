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
int answer;

bool solve(int num)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        res += v[i] / num;
        if (v[i] % num != 0)
            res++;
    }
    return res <= n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int le = 1, ri = v[m - 1];

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