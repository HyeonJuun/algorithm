#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int jump;

bool ck(vector<int> stones, long long num)
{
    int cnt = 0;
    for(int i=0;i <stones.size(); i++)
    {
        if(stones[i] < num)
            cnt++;
        else
            cnt = 0;
        
        if(cnt >= jump)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    jump = k;
    long long left = 0, right = 200000000;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(ck(stones, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return answer;
}