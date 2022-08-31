#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>

using namespace std;

const int MAX = 1000 + 1;

int h[MAX][3];

int n;

int main() 
{
    h[0][0] = 0;
    h[0][1] = 0;
    h[0][2] = 0;
    
    cin >> n;
    int cost[3];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        h[i][0] = min(h[i - 1][1], h[i - 1][2]) + cost[0];
        h[i][1] = min(h[i - 1][0], h[i - 1][2]) + cost[1];
        h[i][2] = min(h[i - 1][1], h[i - 1][0]) + cost[2];
    }
    cout << min(h[n][0], min(h[n][1], h[n][2]));
    return 0;

}