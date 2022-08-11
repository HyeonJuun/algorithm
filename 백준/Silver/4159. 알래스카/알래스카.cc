#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(void)
{
    
    while (true)
    {
        int n;
        cin >> n;
        string ans = "POSSIBLE";
        if (n == 0)
            break;
        else
        {
            vector<int> x;
            for (int i = 0; i < n; i++)
            {
                int a;
                cin >> a;
                x.push_back(a);
            }
            sort(x.begin(), x.end());
            for (int i = 0; i < n - 1; i++)
            {
                if (x[i + 1] - x[i] <= 200)
                {
                    continue;
                }
                else
                    ans = "IMPOSSIBLE";
            }
            if (1422 - x[x.size() - 1] > 100)
                ans = "IMPOSSIBLE";
            cout << ans << endl;
        }
    }
    return 0;
}