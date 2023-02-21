#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[1010];
int arr[1010];
vector<int> ans;

int mx;

int sz, idx;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        int len = 0;
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
                len = max(dp[j], len);
        }
        dp[i] = len + 1;
        if (sz < len + 1)
        {
            sz = len + 1;
            idx = i;
        }
    }
    for (int i = idx; i >= 1; i--)
    {
        if (dp[i] == sz)
        {
            ans.push_back(arr[i]);
            sz--;
        }
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}