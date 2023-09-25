#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int arr1[1000010];
int arr2[1000010];

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    set<int> s;
    for(int i=0; i<n; i++)
    {
        s.insert(topping[i]);
        arr1[i] = s.size();
    }
    s.clear();
    int x =0;
    for(int i = n -1 ; i>= 0; i--)
    {
        s.insert(topping[i]);
        arr2[x++] = s.size();
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr1[i] == arr2[n - 2 - i])
        {
            //cout << arr1[i] << " " << arr2[n-1 - i] << endl;
            answer++;
        }
    }
    
    return answer;
}