#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> mp;
    for(int i=0; i<completion.size(); i++)
    {
        mp[completion[i]]++;
    }
    for(int i=0; i<participant.size(); i++)
    {
        mp[participant[i]]--;
        if(mp[participant[i]] < 0)
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}