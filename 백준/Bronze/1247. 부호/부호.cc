#include <iostream>
#include <climits>
using namespace std;

int main(void){
    long long result=0, overflow=0;
    int n;

    for (int test_case=0; test_case<3; test_case++){
        std::cin>>n;
        
        result   = 0;
        overflow = 0;

        for (int i=0; i < n; i++){
            long long tmp;
            std::cin>>tmp;

            if (result > 0 and tmp > 0 and tmp > LLONG_MAX - result) {
                //result = result + tmp - LLONG_MIN;
                overflow += 1;
            }

            if (result < 0 and tmp < 0 and tmp < LONG_MIN - result) {
                //result = result + tmp - LLONG_MAX;
                overflow -= 1;
            }

            result += tmp;
        }

        if (overflow < 0){
            std::cout<<"-\n";
        }
        else if (overflow > 0){
            std::cout<<"+\n";
        }
        else if (result==0){
            std::cout<<"0\n";
        }
        else if (result < 0){
            std::cout<<"-\n";
        }
        else if (result > 0){
            std::cout<<"+\n";
        }
    }

}