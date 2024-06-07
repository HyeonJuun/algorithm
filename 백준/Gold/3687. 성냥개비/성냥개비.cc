#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define MAX 100 + 1

using namespace std;
/*
1 -> 2개, 2 -> 5개, 3 -> 5개, 4 -> 4개, 5 -> 5개
6 -> 6개, 7 -> 3개, 8 -> 7개, 9 -> 6개, 0 -> 6개
*/
int t, n;
int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
long long mn_dp[MAX];
string mx_answer;

void cal_mn()
{
    for (int i = 1; i < 9; i++)
    {
        mn_dp[i] = num[i];
    }

    mn_dp[6] = 6;

    for (int i = 9; i < 101; i++)
    {
        mn_dp[i] = mn_dp[i - 2] * 10 + num[2];

        for (int j = 3; j < 8; j++)
        {
            mn_dp[i] = min(mn_dp[i], mn_dp[i - j] * 10 + num[j]);
        }
    }
}
int main()
{
    cal_mn();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << mn_dp[n] << ' ';

        mx_answer = "";
        while (n)
        {
            if (n % 2)
            {
                mx_answer += '7';
                n -= 3;
            }
            else
            {
                mx_answer += '1';
                n -= 2;
            }
        }
        cout << mx_answer << endl;
    }
    return 0;
}