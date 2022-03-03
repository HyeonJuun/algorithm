#include <iostream>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int BSearch(int arr[],int n_all, int m_bus,int c_max) {
   
   int low = 0;
   int high = arr[n_all-1];
   
    int  i=1; // 마지막 탑승자 
    int  j=0; // 첫번째 사람 
    int  m=1; //버스 수 
    
   
   while(low<=high)
   
   {
      int mid = (low+high)/2;
      int  i=1; 
      int  j=0;
      int  m=1;
      
      for(i=1;i<n_all;i++)
      {
         if((i-j+1)<= c_max  && arr[i]-arr[j] < mid) 
        {
             continue;  
        }
                   
        else
        {
           m++;
           j=i;  
              
        }
              
           
      }
      
       if(m>m_bus)
       {
          low = mid + 1;   
       }
      
      else
      {
         high = mid - 1;   
      }
       
        
   }
   
   
  return high;
}

int main() {
   
 int n_all=0;
   int m_bus=0;
   int c_max=0;
   int arr[100000];
   int i = 0;
   int a=0;
   

   
   scanf( "%d %d %d", &n_all, &m_bus, &c_max);
    
    for(i =0; i<n_all;i++){
       
        scanf("%d",&arr[i]);        
   }
   
   sort(arr,arr+n_all);
   
    int result = BSearch(arr,n_all,m_bus,c_max);
   
   printf("%d",result);   
   
   return 0;   
   
}

