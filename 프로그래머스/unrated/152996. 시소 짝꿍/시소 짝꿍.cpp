#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> mp(1001, 0);
    
    for(int i=0; i<weights.size(); i++)
    {
        mp[weights[i]]++;
    }
    for(int i=0; i<weights.size(); i++)
    {
        if(weights[i] % 2 == 0)
        {
            long long lo = (weights[i] / 2) * 3;
            if(lo <= 1000)
                answer += mp[lo];
        }
        if(weights[i] % 3 == 0)
        {
            long long lo = (weights[i] / 3) * 4;
            if(lo <= 1000)
                answer += mp[lo];
        }
        
        long long lo = weights[i] * 2;
        if(lo <= 1000)
            answer += mp[lo];
    }
    for(int i= 100; i<= 1000; i++)
    {
        if(mp[i] >= 2)
        {
            answer += (long long)(mp[i] * (mp[i] - 1)) / 2;
        }
    }
    return answer;
}