#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> mp;

    for(int i=0; i<survey.size(); i++)
    {
        if(choices[i] > 4)
        {
            mp[survey[i][1]] += choices[i] - 4;
        }
        else if(choices[i] < 4)
        {
            mp[survey[i][0]] += 4 - choices[i];
        }
    }
    if(mp['R'] >= mp['T'])
        answer += "R";
    else
        answer += "T";
    
    if(mp['C'] >= mp['F'])
        answer += "C";
    else
        answer += "F";
    
    if(mp['J'] >= mp['M'])
        answer += "J";
    else
        answer += "M";
    
    if(mp['A'] >= mp['N'])
        answer += "A";
    else
        answer += "N";
    return answer;
}