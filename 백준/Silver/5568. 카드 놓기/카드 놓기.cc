#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n, k;
map<string, int> mp;
int arr[10];
bool check[10];

void dfs(int dep, string str)
{
    if (dep == k)
    {
        mp[str]++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i] == true)
            continue;
        check[i] = true;
        dfs(dep + 1, str + to_string(arr[i]));
        check[i] = false;
    }
}
int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dfs(0, "");
    cout << mp.size();
    return 0;
}