#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mp;
    for(int i=0; i<26;i ++)
    {
        string tmp = "";
        tmp += i + 'A';
        mp[tmp] = i + 1;
    }
    
    int index = 27;
    string nx;
    bool flag = false;
    for(int i =0; i<msg.length(); i++)
    {
        nx = "";
        //cout << i << " " << msg.length() << " ";
        
        for(int j=i; j<msg.length(); j++)
        {
            nx += msg[j];
            if(mp[nx] == 0)
            {
                mp[nx] = index++;
                //cout << nx << " ";
                nx.pop_back();
                i = i + nx.length() - 1;
                answer.push_back(mp[nx]);
                //cout << nx << " " << mp[nx] << " " << i <<  endl;
                
                break;
            }
            if(j == msg.length() -1 && mp[nx] != 0)
            {
                //cout << nx << " " << mp[nx] << endl;
                flag = true;
                answer.push_back(mp[nx]);
                break;
            }
        }
        if(flag)
            break;
    }
    
    return answer;
}