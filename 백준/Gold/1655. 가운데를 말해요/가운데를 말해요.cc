#include<iostream>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    priority_queue<int> max; //작은것들의 max값이 top
    priority_queue<int,vector<int>,greater<int>> min; //큰것들의 min값이 top

    while (t--) {
        int a, size;
        cin >> a;
        if (max.size() == min.size()) {
            max.push(a);
        }
        else {
            min.push(a);
        }
        if (!max.empty()&&!min.empty()&&max.top()>min.top()) {
            int max_val, min_val;
            max_val = max.top();
            min_val = min.top();
            max.pop();
            min.pop();
            max.push(min_val);
            min.push(max_val);


        }
        cout << max.top() << '\n';
    }



    return 0;
}