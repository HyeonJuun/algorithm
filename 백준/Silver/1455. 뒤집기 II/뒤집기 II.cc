#include<iostream>
#include<algorithm>

using namespace std;

int coin[101][101];
void Reverse(int y, int x)
{
    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            coin[i][j] = 1 - coin[i][j];
        }
    }
}
int main(void)
{
    int n, m,  ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &coin[i][j]);
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            if (coin[i][j] == 1)
            {
                Reverse(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}