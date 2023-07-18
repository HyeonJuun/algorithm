#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    map<string, vector<int>> m;
    
    for(int i=0; i< info.size(); i++)
    {
        string token;
        stringstream ss(info[i]);
        vector<vector<string>> str(4, vector<string>(2, "-"));
        int ind = 0, score = 0;
        
        while(ss >> token)
        {
            if(ind < 4)
                str[ind++][0] = token;
            else
                score = stoi(token);
        }
        
        for(int i=0; i<2; i++)
        {
            string s1, s2, s3, s4;
            s1 = str[0][i];
            for(int j=0; j<2; j++)
            {
                s2 = str[1][j];
                for(int k=0; k<2; k++)
                {
                    s3 = str[2][k];
                    for(int l=0; l<2; l++)
                    {
                        s4 = str[3][l];
                        m[s1 + s2 + s3 + s4].push_back(score);
                    }
                }
            }
        }
    }
    for(auto it = m.begin(); it != m.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
        }
    
    for(int i=0; i<query.size(); i++)
    {
        string str = "", token;
        stringstream ss(query[i]);
        
        int ind = 0, score = 0;
        
        while(ss >> token)
        {
            if(token == "and")
                continue;
            
            if(ind++ < 4)
                str += token;
            else
                score = stoi(token);
        }
        auto it = lower_bound(m[str].begin(), m[str].end(), score);
        answer[i] = m[str].size() - (it - m[str].begin());
    }
    return answer;
}