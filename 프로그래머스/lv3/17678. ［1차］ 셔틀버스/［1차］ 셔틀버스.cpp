#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// "hh:mm" -> X분으로 바꾸는 Key 기억하기
// 첫 버스가 시작되는 09:00 -> 540으로 변경
// 마지막 버스일 때 m명 안에 드는지 확인하고 못든다면 마지막 사람보다 1분 전에 오기
// 마지막으로 X분 -> "hh:mm"으로 바꾸는 방법은 substr + string 디테일을 살려야 한다.
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    sort(timetable.begin(), timetable.end());
    
    vector<int> tt;
    for(int i=0; i<timetable.size(); i++)
    {
        tt.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));
    }
    int index = 0;
    int bus = 540;
    int res = 0;
    for(int i=1; i<=n; i++)
    {
        int num = 0;
        while(num < m && index < tt.size())
        {
            if(tt[index] <= bus)
            {
                num++;
                index++;
            }
            else
                break;
        }
        if(i == n)
        {
            if(num < m)
                res = bus;
            else
                res = tt[index - 1] - 1;
        }
        bus += t;
    }
    int h = res / 60;
    int mi = res % 60;
    
    if(h < 10)
        answer += "0" + to_string(h) + ":";
    else
        answer += to_string(h) + ":";
    
    if(mi < 10)
        answer += "0" + to_string(mi);
    else
        answer += to_string(mi);
    return answer;
}