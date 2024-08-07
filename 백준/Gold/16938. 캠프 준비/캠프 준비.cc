#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 2500 + 10
#define INF 987654321

int n, l, r, x;
vector<long long> arr;
bool visited[30];
int answer = 0;

void solve(int idx, int ed, int sum)
{
    if (sum > r)
        return;
    if (l <= sum && sum <= r)
    {
        if (arr[ed] - arr[idx] >= x)
            answer++;
    }
    for (int i = ed + 1; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        solve(idx, i, sum + arr[i]);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        solve(i, i, arr[i]);
        visited[i] = false;
    }
    cout << answer << endl;
    return 0;
}