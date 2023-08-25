#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<int> arrows) {
    int answer = 0;
    
    map<pair<int, int>, bool> nodeVisited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edgeVisited;
    
    int x = 0, y = 0;
    nodeVisited[{x, y}] = true;
    
    for(int i=0; i<arrows.size(); i++)
    {
        int dir = arrows[i];
        for(int j=0; j<2; j++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nodeVisited[{nx, ny}] == true && edgeVisited[{{x, y}, {nx, ny}}] == false)
            {
                edgeVisited[{{x, y}, {nx, ny}}] = true;
                edgeVisited[{{nx, ny}, {x, y}}] = true;
                answer++;
                x = nx;
                y = ny;
                continue;
            }
            
            nodeVisited[{nx, ny}] = true;
            edgeVisited[{{x, y}, {nx, ny}}] = true;
            edgeVisited[{{nx, ny}, {x, y}}] = true;
            x = nx;
            y = ny;
        }
    }
    return answer;
}