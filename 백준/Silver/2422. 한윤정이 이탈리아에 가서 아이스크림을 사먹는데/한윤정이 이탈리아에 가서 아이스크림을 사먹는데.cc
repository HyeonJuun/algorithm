#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
 
int N, M, set[5], cnt;
vector<int> no[205];
 
void DFS(int x, int depth)
{
    if (depth == 4)
    {
        for (int i = 1; i <= 3; ++i)
        {
            for (auto num : no[set[i]])
            {
                if (i == 1)
                {
                    if (num == set[2] || num == set[3]) return;
                }
                else if (i == 2)
                {
                    if (num == set[1] || num == set[3]) return;
                }
                else if (i == 3)
                {
                    if (num == set[1] || num == set[2]) return;
                }
            }
        }
        ++cnt;
        return;
    }
 
    for (int i = x; i <= N; ++i)
    {
        set[depth] = i;
        DFS(i + 1, depth + 1);
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int p, q;
        cin >> p >> q;
        no[p].push_back(q);
    }
    DFS(1, 1);
    cout << cnt << endl;
    return 0;
}
