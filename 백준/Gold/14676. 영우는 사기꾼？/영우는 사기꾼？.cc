#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define MAX 100000 + 1

using namespace std;

int n, m, k;
bool answer = true;
vector<int> v[MAX];
int inDegree[MAX];
int
    requires[
        MAX];
int constructed[MAX];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        requires[b]++;
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            if (inDegree[b] != requires[b])
            {
                answer = false;
                break;
            }
            constructed[b]++;
            if (constructed[b] == 1)
            {
                for (int nxt : v[b])
                {
                    inDegree[nxt]++;
                }
            }
        }
        if (a == 2)
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
                    for (int nxt : v[b])
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