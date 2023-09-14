#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> mp;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0; i <want.size(); i++)
    {
        mp[want[i]] = number[i];
    }
    
    for(int i=0; i<= discount.size() - 10; i++)
    {
        map<string, int> dismp;
        
        for(int j=i; j<i + 10; j++)
        {
            dismp[discount[j]]++;
        }
        if(dismp == mp)
            answer++;
    }
    return answer;
}