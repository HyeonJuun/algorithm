#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mxsize = 0, mnsize= 0;
    for(int i=0; i<sizes.size(); i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            if(mxsize < sizes[i][0])
                mxsize = sizes[i][0];
            if(mnsize < sizes[i][1])
                mnsize = sizes[i][1];
        }
        else
        {
            if(mnsize < sizes[i][0])
                mnsize = sizes[i][0];
            if(mxsize < sizes[i][1])
                mxsize = sizes[i][1];
        }
    }
    answer = mxsize * mnsize;
    return answer;
}