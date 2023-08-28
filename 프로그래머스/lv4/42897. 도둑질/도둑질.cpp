#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int dp0[1000000];
    int dp1[1000000];
    int n = money.size() - 1;
    dp0[0] = money[0];
    dp0[1] = dp0[0];
    for(int i=2; i<n; i++)
    {
        dp0[i] = max(dp0[i-2] + money[i], dp0[i-1]);
    }
    dp1[0] = 0;
    dp1[1] = money[1];
    for(int i=2; i<=n; i++)
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    
    if(dp1[n] > dp0[n-1])
        answer = dp1[n];
    else
        answer = dp0[n-1];
    return answer;
}