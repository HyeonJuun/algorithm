#include <string>
#include <vector>

using namespace std;

int lx = 2e9, ly = 2e9, rx = -1, ry = -1;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                lx = min(lx, i);
                ly = min(ly, j);
                rx = max(rx, i + 1);
                ry = max(ry, j + 1);
            }
        }
    }
    answer.push_back(lx);
    answer.push_back(ly);
    answer.push_back(rx);
    answer.push_back(ry);
    
    return answer;
}