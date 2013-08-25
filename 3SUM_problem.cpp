#include<iostream>
using namespace std;

//printing triplets which sum to 0, the traditional 3SUM problem -- http://en.wikipedia.org/wiki/3SUM

int main()
{
  int n;
  cin>>n;
  
  int A[n];
  for(int i = 0; i < n; i++)
   cin >> A[i];
  
  sort(A,A+n);
   
  for(int i = 0; i <= n-3; i++){
     int a = A[i];  
     int k = i+1;
     int l = n-1;
     while(k < l){
       int b = A[k];
       int c = A[l];
       
       if(a+b+c == 0) {
                cout<< a <<" "<< b <<" "<< c << endl;
                k++; // assumption: Duplicate elements are not present in array
                l--; // assumption: Duplicate elements are not present in array
       }
       else if(a+b+c > 0) l = l-1;
       else k = k + 1;    
     }
  }

  system("pause");
  return 0;
}
