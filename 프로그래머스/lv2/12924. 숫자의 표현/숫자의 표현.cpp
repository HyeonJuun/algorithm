#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int start =0, end = 0;
    long long sum = 0;
    while(end <= n)
    {
        if(sum < n)
        {
            end++;
            sum += end;
        }
        else if(sum > n)
        {
            sum -= start;
            start++;
        }
        if(sum == n)
        {
            answer++;
            end++;
            sum += end;
        }
    }
    
    return answer;
}