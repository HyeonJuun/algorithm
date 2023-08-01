#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    stack<int> st;
    
    for(int i=0; i<ingredient.size(); i++)
    {
        if(st.empty())
            st.push(ingredient[i]);
        else
        {
            if(ingredient[i] == 1)
            {
                if(st.top() != 123)
                    st.push(1);
                else if(st.top() == 123)
                {
                    st.pop();
                    answer++;
                }
            }
            if(ingredient[i] == 2 && st.top() == 1)
            {
                st.pop();
                st.push(12);
            }
            else if(ingredient[i] == 2 && st.top() != 1)
                st.push(2);
            
            if(ingredient[i] == 3 && st.top() == 12)
            {
                st.pop();
                st.push(123);
            }
            else if(ingredient[i] == 3 && st.top() != 12)
            {
                st.push(3);
            }
        }
    }

    return answer;
}