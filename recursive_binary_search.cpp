#include<iostream>
using namespace std;

int recursiveBS(int*a, int p, int r, int n){
 if(r < p) return -1;
 int q = (p+r)/2;
 if(a[q] > n)
  return recursiveBS(a,p,q-1,n);
 else if(a[q] < n)
  return recursiveBS(a,q+1, r, n);
 else
  return q;
}

int main()
{
  int a[10] = {1,5,8,12,69,78,79,80,93,1000};
  int pos = recursiveBS(a,0,9,68);
  if(pos != -1)
  cout<<pos+1<<endl;
  else
  cout<<"Number doesn't exit"<<endl;
  
  system("pause");
  return 0;
}
