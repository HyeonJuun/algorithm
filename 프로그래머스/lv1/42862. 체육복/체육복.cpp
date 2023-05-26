#include <vector>
#include <iostream>
 
using namespace std;
 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cnt(n, 1);
    for(auto i : lost)
        if(i)   cnt[i-1]--;
    for(auto i : reserve)
        if(i)   cnt[i-1]++;
    
    for(int i=0 ; i<cnt.size(); i++)
    {
        if(cnt[i] == 0)
        {
            if(i != 0 && cnt[i-1] == 2)
            {
                cnt[i-1] = 1;
                cnt[i] = 1;
                continue;
            }
            else if(i != cnt.size() && cnt[i+1] == 2)
            {
                cnt[i+1] = 1;
                cnt[i] = 1;
                continue;
            }
        }
    }
    for(auto i : cnt)
    {
        if(i)
            answer++;
    }
    return answer;
}