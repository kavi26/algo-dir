#include<iostream>
using namespace std;

int ceilBinarySearch(int*, int, int, int);
int LIS(int*, int);

int main()
{
  int a[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6};
  int length = LIS(a,sizeof(a)/sizeof(int));
  cout<<length<<endl;
  system("pause");
  return 0;
}

int LIS(int*a, int length){
    int end[length];
    int seqLIS[length]; // stores the LIS(more precisely the LIS with end element as end[len-1])
    end[0] = a[0];
    seqLIS[0] = end[0];
    int len = 1;
    for(int i = 0; i < length; i++){
     if(a[i] < end[0]){
      end[0] = a[i];
      continue;        
     }        
     else if(a[i] > end[len-1]){
           end[len] = a[i];
           seqLIS[len] = a[i];
           len++;
           continue;
          }
          else{
           int ind = ceilBinarySearch(end,0,len-1,a[i]);
           end[ind] = a[i];    
           if(ind == len-1) seqLIS[len-1] = a[i]; 
          }
    } 
    for(int i = 0; i < len; i++) cout<<seqLIS[i]<<" ";
    cout<<endl;
    return len;    
}


int ceilBinarySearch(int*end,int a, int b, int v){
    if(b <= a) return a;
    int mid = (a+b)/2;
    if(end[mid] < v) return ceilBinarySearch(end,mid+1,b,v);
    else return ceilBinarySearch(end,a,mid,v);
}
