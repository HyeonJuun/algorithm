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

#define MAX 1000000 + 10
#define INF 2100000000

int n;
vector<int> arr, res;
int find_lowerbound(vector<int> &arr, int key)
{
    int st = 0;
    int ed = arr.size() - 1;
    int result = 0;
    while (st < ed)
    {
        int mid = (st + ed) / 2;
        if (key > arr[mid])
        {
            st = mid + 1;
        }
        else
            ed = mid;
    }
    return ed;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 1;
    res.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (res.back() < arr[i])
        {
            res.push_back(arr[i]);
            cnt++;
        }
        else
        {
            int idx = find_lowerbound(res, arr[i]);
            res[idx] = arr[i];
        }
    }
    cout << cnt << endl;
    return 0;
}