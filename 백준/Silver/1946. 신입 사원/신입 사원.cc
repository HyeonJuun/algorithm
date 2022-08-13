#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,N;

int main() {
    cin >> T;

    while(T--) {
        cin >> N;
        
        vector<pair<int,int>> grades;
        
        for(auto i=0;i<N;i++) {
            int x,y;
            cin >> x>>y;
            grades.push_back({x,y});
        }

        sort(grades.begin(),grades.end());

        int temp=0;
        int result=1;

        for(auto i=1;i<N;i++) {
            if(grades[temp].second > grades[i].second) {
                result++;
                temp=i;
            }
        }
        cout << result<<"\n";
    }
}
