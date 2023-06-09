#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> sum;
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j= i + 1; j<numbers.size(); j++)
        {
            int s = numbers[i] + numbers[j];
            sum.insert(s);
        }
    }
    for(auto i : sum)
    {
        answer.push_back(i);
    }
    return answer;
}