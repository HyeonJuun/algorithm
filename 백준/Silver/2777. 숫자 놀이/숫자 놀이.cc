#include<iostream>
#include<algorithm>

using namespace std;
int level[101];

int main(void)
{
    int t, n;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n;
        if (n < 10)
        {
            cout << "1" << endl;
            continue;
        }
        for (int i = 9; i >= 2; i--)
        {
            while (n % i == 0)
            {
                ++ans;
                n /= i;
            }

            if (n == 1) break;
        }

        cout << (n == 1 ? ans : -1) << endl;
    }
    return 0;
}