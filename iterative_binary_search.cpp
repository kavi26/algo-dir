#include<iostream>
using namespace std;

int iterativeBS(int*a,int size, int n){
    int p = 0;
    int q = size - 1;
    while(q >= p){
      int mid = (p+q)/2;
      if(a[mid] > n){
       q = mid - 1;
       continue;
      }
      else if(a[mid] < n){
       p = mid + 1; 
       continue;    
      }
      else
       return mid;
    }
    
    return -1;
}

int main()
{
  int a[10] = {1,5,8,12,69,78,79,80,93,1000};
  int pos = iterativeBS(a,10,79);
  if(pos != -1)
  cout<<pos+1<<endl;
  else
  cout<<"Number doesn't exit"<<endl;
  
  system("pause");
  return 0;
}
