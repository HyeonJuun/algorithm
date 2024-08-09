#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

int k, n, f;
vector<int> v[MAX];
int arr[MAX][MAX];
vector<int> answer;
bool visited[MAX];

bool solve(int cur)
{

    if (answer.size() == k)
        return 1;
    else
    {

        for (int i = cur + 1; i <= n; i++)
        {
            bool flag = true;

            for (auto x : answer)
            {
                if (!arr[i][x])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                answer.push_back(i);
                if (solve(i))
                    return 1;
                answer.pop_back();
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n >> f;
    for (int i = 0; i < f; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        answer.push_back(i);
        if (solve(i))
        {
            for (auto f : answer)
            {
                cout << f << endl;
            }
            return 0;
        }
        answer.clear();
    }
    cout << -1 << endl;
    return 0;
}