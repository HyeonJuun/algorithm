#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define endl '\n'

using namespace std;

int answer;
bool chk(vector<int> diffs, vector<int>times, long long limit, int num)
{
    long long res = 0;
    vector<int> prev(times.size() + 1);
    
    for(int i=0; i< diffs.size(); i++)
    {
        if(diffs[i] <= num)
        {
            res += times[i];
            prev[i] = times[i];
        }
        else
        {
            int lev = diffs[i] - num;
            int t = (lev * (times[i-1] + times[i])) + times[i];
            prev[i] = t;
            res += t;
        }
    }
    return res <= limit;
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int st = 1, ed = *max_element(diffs.begin(), diffs.end()) * 2;
    
    while(st <= ed)
    {
        int mid = (st + ed) / 2;
        if(chk(diffs, times, limit, mid))
        {
            answer = mid;
            ed = mid -1;
        }
        else
            st = mid + 1;
    }
    return answer;
}