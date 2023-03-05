#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

int n;
int arr[110];
bool visited[110];

set<int> ans;
bool isRight;
void dfs(int firstNum, int num)
{
    if (visited[num])
    {
        if (firstNum == num)
        {
            isRight = true;
            ans.insert(num);
        }
        return;
    }
    visited[num] = true;
    dfs(firstNum, arr[num]);
    if (isRight)
    {
        ans.insert(num);
        ans.insert(arr[num]);
    }
}
int main() {
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        visited[i] = true;
        dfs(i, arr[i]);
        memset(visited, false, sizeof(visited));
        isRight = false;
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << '\n';
    return 0;
}