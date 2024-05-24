#include <string>
#include <vector>
#include <set>
using namespace std;

int tt[1000001]; //out
int tt2[1000001]; //int
vector<int> solution(vector<vector<int>> edges) {
    int maxNum=0;
    vector<int> answer(4,0);
    for (int i=0; i<edges.size(); i++){
        tt[edges[i][0]]+=1;
        tt2[edges[i][1]]+=1;
        if (maxNum<edges[i][0])
        {
            maxNum=edges[i][0];
        }
        if (maxNum<edges[i][1])
        {
            maxNum=edges[i][1];
        }
    }

    int stN;
    for (int i=1; i<=maxNum; i++)
    {
        if (tt[i]>=2)
        {
            answer[3]+=1;
            if (tt2[i]==0)
            {
                stN=i;
                answer[3]-=1;
            }
        }
        if (tt2[i]>=1)
        {
            if(tt[i]==0)
            {
                answer[2]+=1;
            }
        }
    }
    answer[0]=stN;
    answer[1]=tt[stN]-answer[2]-answer[3];
    return answer;
}