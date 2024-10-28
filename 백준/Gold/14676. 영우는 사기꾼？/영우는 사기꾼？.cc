#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 100000 + 10
#define INF 2e9
using namespace std;

int n, m, k;
bool answer = true;
int x, y;
int a, b;

vector<int> graph[MAX];
int required[MAX];
int inDegree[MAX];
int constructed[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        required[y]++;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        if (a == 1)
        {
            if (inDegree[b] != required[b])
            {
                answer = false;
                break;
            }
            else
            {
                constructed[b]++;
                if (constructed[b] == 1)
                {
                    for (int nxt : graph[b])
                    {
                        inDegree[nxt]++;
                    }
                }
            }
        }
        else
        {
            if (constructed[b] == 0)
            {
                answer = false;
                break;
            }
            else
            {
                constructed[b]--;
                if (constructed[b] == 0)
                {
                    for (int nxt : graph[b])
                    {
                        inDegree[nxt]--;
                    }
                }
            }
        }
    }
    if (answer)
        cout << "King-God-Emperor" << endl;
    else
        cout << "Lier!" << endl;
    return 0;
}