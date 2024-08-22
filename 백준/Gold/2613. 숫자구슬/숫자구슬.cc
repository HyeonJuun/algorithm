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

int n, m, x, total;
vector<int> v;
vector<int> answer;
int ans;
bool solve(int num)
{
    int res = 1;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (sum + v[i] <= num)
        {
            sum += v[i];
        }
        else
        {
            if (v[i] <= num)
                sum = v[i];
            else
                return false;
            res++;
        }
    }

    return res <= m;
}
void makeGroup(int num)
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (sum + v[i] <= num)
        {
            sum += v[i];
            cnt++;
        }
        else
        {
            answer.push_back(cnt);
            sum = v[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);

    while (answer.size() < m)
    {
        for (int i = answer.size() - 1; i > -1; i--)
        {
            if (answer[i] > 1)
            {
                answer.insert(answer.begin() + i + 1, answer[i] / 2);
                answer[i] = answer[i] - answer[i] / 2;
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    int le = 1, ri = 30000, ans = 30000;

    while (le <= ri)
    {
        int mid = (le + ri) / 2;

        if (solve(mid))
        {
            ans = mid;
            ri = mid - 1;
        }
        else
            le = mid + 1;
    }
    makeGroup(ans);

    cout << ans << endl;

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}