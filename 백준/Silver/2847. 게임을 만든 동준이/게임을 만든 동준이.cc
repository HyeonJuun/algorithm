#include<iostream>
#include<algorithm>

using namespace std;
int level[101];

int main(void)
{
    int n,  ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> level[i];

    for (int i = n-1; i >0; i--)
    {
        while (level[i] <= level[i - 1]) 
        {
            level[i - 1] -= 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}