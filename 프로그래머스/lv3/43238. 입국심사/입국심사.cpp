#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> t;
bool ck(long long mid)
{
    long long res = 0;
    for(int i=0; i<t.size(); i++)
    {
        res += (mid / (long long)t[i]);
        if(res >= N)
            return true;
    }
        return false;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    N = n;
    t = times;
    long long start = 1, end = n * (long long)times.back();
    while(start <= end)
    {
        long long mid = (start + end) / 2;
        
        for(int i=0; i<times.size(); i++)
        {

        }
        if(ck(mid))
        {
            end = mid - 1;
            answer = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return answer;
}