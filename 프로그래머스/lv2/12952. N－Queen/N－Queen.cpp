#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N, answer;
int arr[15];

bool check(int num)
{
    for(int i=0; i<num; i++)
    {
        if(arr[i] == arr[num])
            return false;
        if(abs(arr[i] - arr[num]) ==  num - i)
            return false;
    }
    return true;
}
void dfs(int num)
{
    if(num == N)
    {
        answer++;
        return;
    }
    for(int i=0; i<N; i++)
    {
        arr[num] = i;
        if(check(num))
        {
            dfs(num + 1);
        }
        arr[num] = 0;
    }
    return;
}
int solution(int n) {
    
    N = n;
    dfs(0);
    return answer;
}