#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

set<int> numSet;
bool ckPrime(int num)
{
    if(num<2) 
        return false;
    
    for(int i=2; i<=sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}
void makeNum(string num, string others)
{
    if(num != "")
    {
        numSet.insert(stoi(num));
    }
    for(int i=0; i<others.size(); i++)
    {
        makeNum(num + others[i], others.substr(0, i) + others.substr(i+1));
    }
}
int solution(string numbers) {
    int answer = 0;
    
    makeNum("", numbers);
    
    for(int num : numSet)
    {
        if(ckPrime(num))
            answer++;    
    }
    
    
    return answer;
}