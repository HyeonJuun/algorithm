#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int dep, int sum, int target)
{
    if(dep == numbers.size() - 1)
    {
        if(sum == target)
            answer++;
        return;
    }
    dfs(numbers, dep + 1, sum + numbers[dep + 1], target);
    dfs(numbers, dep + 1, sum - numbers[dep + 1], target);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, 0, numbers[0], target);
    dfs(numbers, 0, (-1)*numbers[0], target);
    
    return answer;
}