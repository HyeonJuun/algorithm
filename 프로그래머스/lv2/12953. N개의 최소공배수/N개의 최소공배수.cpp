#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a%b);
}
int solution(vector<int> arr) {
    int answer = 1;
    if(arr.size() < 2)
    {
        return arr[0];
    }
    
    answer = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    for(int i=2; i<arr.size(); i++)
    {
        int g = gcd(answer, arr[i]);
        answer = answer * arr[i] / g;
    }
    return answer;
}