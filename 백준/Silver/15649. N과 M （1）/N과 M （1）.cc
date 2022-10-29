#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9];
int select_arr[9];
bool visited[9];
int n, m;

void dfs(int num, int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << select_arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            select_arr[k] = arr[i];
            dfs(i, k + 1);
            visited[i] = false;
        }
    }

}
int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    dfs(1, 0);
    return 0;
}