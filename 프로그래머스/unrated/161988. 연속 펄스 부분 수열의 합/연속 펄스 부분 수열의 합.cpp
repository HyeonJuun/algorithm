#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ckPurse(vector<int> s, int num)
{
    for(int i=0; i<s.size(); i++)
    {
        s[i] = s[i] * num;
        num *= -1;
    }
    
    return s;
}
long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int n = sequence.size();
    
    vector<int> se1 = ckPurse(sequence, 1);
    vector<int> se2 = ckPurse(sequence, -1);
    
    vector<long long> dp1(n, -1);
    vector<long long> dp2(n, -1);

    dp1[0] = se1[0];
    dp2[0] = se2[0];
    
    for(int i=1; i<n; i++)
    {
        dp1[i] = max(dp1[i - 1] + (long long)se1[i], (long long)se1[i]);
        answer = max(answer, dp1[i]);
    }
    for(int i=1; i<n; i++)
    {
        dp2[i] = max(dp2[i - 1] + (long long)se2[i], (long long)se2[i]);
        answer = max(answer, dp2[i]);
    }
    if(n == 1)
        answer = max(se1[0], se2[0]);
    
    return answer;
}