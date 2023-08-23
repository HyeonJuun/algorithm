#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start_time, end_time;
    
    for(int i=0; i<lines.size(); i++)
    {
        string h, m, s, ms;
        
        int ih, im, is, process;
        
        lines[i].pop_back();
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        
        process = stof(lines[i].substr(24, 5)) * 1000;
        
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms);
        
        start_time.push_back(ih + im + is - process + 1);
        end_time.push_back(ih + im + is);
    }
    
    for(int i=0; i<lines.size(); i++)
    {
        int eT = end_time[i] + 1000;
        int cnt = 0;
        
        for(int j = i; j< lines.size(); j++)
        {
            if(start_time[j] < eT)
                cnt++;
        }
        
        if(answer < cnt)
            answer = cnt;
    }
    return answer;
}