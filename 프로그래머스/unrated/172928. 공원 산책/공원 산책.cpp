#include <string>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int arr[51][51];

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int x = 0, y = 0;
    int w = park[0].size();
    int h = park.size();
    
    for(int i=0; i<park.size(); i++)
    {
        for(int j=0; j<park[i].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }
    for(int i=0; i<routes.size(); i++)
    {
        char op = routes[i][0];
        int n = routes[i][2] - '0';
        bool flag = true;
        if(op == 'N')
        {
            for(int j=1; j<=n; j++)
            {
                if(x - j < 0 || park[x - j][y] == 'X')
                {
                    flag = false;
                }
            }
            if(flag)
                x -= n;
        }
        else if(op == 'S')
        {
            for(int j=1; j<=n; j++)
            {
                if(x + j >= h || park[x + j][y] == 'X')
                {
                    flag = false;
                }
            }
            if(flag)
                x += n;
        }
        else if(op == 'W')
        {
            for(int j=1; j<=n; j++)
            {
                if(y - j < 0 || park[x][y- j] == 'X')
                {
                    flag = false;
                }
            }
            if(flag)
                y -= n;
        }
        else if(op == 'E')
        {
            for(int j=1; j<=n; j++)
            {
                if(y + j >= w || park[x][y + j] == 'X')
                {
                    flag = false;
                }
            }
            if(flag)
                y += n;
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}