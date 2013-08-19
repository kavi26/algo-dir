/************Read from here:- http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor#Segment_Trees***************/
/************Must read from topcoder tutorial**********************************/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<fstream>
#include<cstring>
using namespace std;


#define MAXN 1000000

int M[MAXN][64]; //64 is log(N) and MAXN is number of elements in array.
//M[i][j] represents minimum value in the interval of length 2^j starting at i.

void preprocess(int*A,int n){
     int i,j;
     // initialize M for interval with length 1, i.e. the element itself.
     for(i=0;i<n;i++) 
      M[i][0] = i;
      
     // Now minimum value of interval [i,j] is minimum of the two equal halves in interval [i,j] since for smaller interval min value is already processed.
     for(j=1;(1<<j)<=n;j++) //********IMPORTANT*********** 1<<j IS EQUIVALENT TO 2^j*****************IMPORTANT********//
         for(i=0;i<n;i++)
            if(A[M[i][j-1]]<= A[M[i + (1<<(j-1)) ][ j-1 ]])
              M[i][j] = M[i][j-1];
            else
              M[i][j] = M[i + (1<<(j-1)) ][ j-1 ];
}
                        
int main()
{
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++) cin>>A[i];
 
  preprocess(A,n);
  
  cout<<"Interval:- ";
  int i,j;
  cin>>i>>j;
  
  int k = int((log10(j-i+1))/(log10(2.0)));
  
  if(A[M[i][k]]<=A[M[j+1-(1<<k)][k]])
   cout<<"RMQ Position:- "<<M[i][k]<<" and element:- "<<A[M[i][k]]<<endl;
  else
   cout<<"RMQ Position:- "<<M[j+1-(1<<k)][k]<<" and element:- "<<A[M[j+1-(1<<k)][k]]<<endl;
   
  system("pause");
  return 0;
}
