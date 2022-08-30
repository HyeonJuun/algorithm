#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>

using namespace std;

const int MAX = 250 + 1;
string dp[MAX];

int n;

string tile(string num1, string num2)
{
    long long sum = 0;
    string res;

    while (!num1.empty() || !num2.empty() || sum)
    {
        if (!num1.empty())
        {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty())
        {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        res.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() 
{
    dp[0] = dp[1] = '1';
    for (int i = 2; i <= 250; i++)
    {
        dp[i] = tile(tile(dp[i - 2], dp[i - 2]), dp[i - 1]);
    }
    
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}