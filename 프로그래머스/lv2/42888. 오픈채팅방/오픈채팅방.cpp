#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> uid_list;
    queue<pair<string, string>> que;
    
    for(int i=0; i<record.size(); i++)
    {
        stringstream ss(record[i]);
        
        string elc, uid, name;
        ss >> elc >> uid >> name;
        if(elc == "Enter")
        {
            que.push({"enter", uid});
            uid_list[uid] = name;
        }
        else if(elc == "Leave")
        {
            que.push({"leave", uid});
        }
        else if(elc == "Change")
        {
            uid_list[uid] = name;
        }
    }

    while(!que.empty())
    {
        string elc = que.front().first;
        string uid = que.front().second;
        
        string ans = uid_list[uid];
        que.pop();
        if(elc == "enter")
        {
            ans += "님이 들어왔습니다.";
        }
        else if(elc == "leave")
        {
            ans += "님이 나갔습니다.";
        }
        answer.push_back(ans);
    }
    return answer;
}