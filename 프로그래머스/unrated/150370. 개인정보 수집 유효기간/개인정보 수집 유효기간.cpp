#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

map<char, int> t_map;


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i=0; i<terms.size(); i++)
        t_map[terms[i][0]] = stoi(terms[i].substr(2, terms[i].length() - 2));
    
    string t_year, t_month, t_day;
    t_year = today.substr(0, 4);
    t_month = today.substr(5, 2);
    t_day = today.substr(8, 2);
    
    int tcount = stoi(t_year) * 12 * 28 + (stoi(t_month) - 1) * 28 + stoi(t_day);
    for(int i=0; i<privacies.size(); i++)
    {
        char c;
        string year, month, day;
        year = privacies[i].substr(0, 4);
        month = privacies[i].substr(5, 2);
        day = privacies[i].substr(8, 2);
        
        int tmp = stoi(year) * 12 * 28 + (stoi(month) - 1) * 28 + stoi(day);     
        tmp += (t_map[privacies[i].back()] * 28) - 1;
        cout << tmp << " " << tcount << endl;
        if(tmp < tcount)
            answer.push_back(i + 1);
    }
    return answer;
}