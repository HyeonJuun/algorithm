#include<vector>
#include <algorithm>

using namespace std;

long long arr[90001], sum[90001];
long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = -1;
    int ind = 1;
    int n = land.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            arr[ind++] = land[i][j];
    }
    sort(arr, arr+(land.size() * land.size()) + 1);
    n *= n;
    for(int i=1; i<=n; i++)
        sum[i] = sum[i-1] + arr[i];
    
    int cur = -1;
    
    for(int i=1; i<=n; i++)
    {
        if(arr[i] == cur)
            continue;
        cur = arr[i];
        long long x = 0;
        x += (sum[n] - sum[i-1] - arr[i] *(n-(i-1))) * Q;
        x += (arr[i] * (i-1) - sum[i-1]) * P;
        if(answer == -1 || answer > x)
            answer = x;
    }
    return answer;
}