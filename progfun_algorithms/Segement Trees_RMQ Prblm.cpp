/** Segment Tree Implementation for solving Range Minimum Query(RMQ) problem while updating array elements # Topcoder Tutorial**************************/
/****************************http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor#Segment_Trees**************************/
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

int gcd(int a,int b) // Euclid's Algorithm
{ int t;
  while(b != 0){t = b;
                b = a%b;//b works as remainder
                a = t;}
  return a;
}

int lcm(int a,int b)
{
  return (a*b)/gcd(a,b);
}

void initialize(int node, int b, int e, int*M,int*A){
     if(b==e)
    {  M[node]= b; cout<<"Node:- "<<node<<" & value:- "<<M[node]<<endl;}
     else{ //compute the values in the left and right subtrees
          initialize(2*node,b,(b+e)/2,M,A);
          initialize(2*node+1,(b+e)/2+1,e,M,A);
          
           //search for the minimum value in the first and second half of the interval
          
          if(A[M[2*node]]<A[M[2*node+1]])
         {  M[node] = M[2*node];cout<<"Node:- "<<node<<" & value:- "<<M[node]<<endl;}
          else
          { M[node] = M[2*node+1];cout<<"Node:- "<<node<<" & value:- "<<M[node]<<endl;}
     }
}

int query(int node, int b, int e, int*M,int*A,int i, int j){ 
    if(i==j)
     return i;
     
    int p1,p2;
    
    if(i>e || j<b) // Interval [b,e] && [i,j] don't intersect.
     return -1;
    
    if(b>=i && e<=j)
     return M[node];
    
    p1 = query(2*node,b,(b+e)/2,M,A,i,j); // Position of minimum value in left subtree rooted at "node"
    p2 = query(2*node+1,(b+e)/2+1,e,M,A,i,j); // Position of minimum value in right subtree rooted at "node"
    
    if(p1==-1) 
     return p2;
    
    if(p2==-1) 
     return p1;
     
    if(A[p1]<=A[p2])
     return p1;
    else
     return p2;
}

void update(int node, int b, int e, int*M,int*A, int pos){ // If a value of array A is changed at position "pos"
    if(b==e) return;
    
    if(pos<=(b+e)/2) update(2*node,b,(b+e)/2,M,A,pos);
    else update(2*node+1,(b+e)/2+1,e,M,A,pos);
    
    if(A[M[2*node]]<A[M[2*node+1]])
      M[node] = M[2*node];
    else
      M[node] = M[2*node+1];
         
}            

int main()
{
  int n;
  cin>>n;  // Number of elements in array A.
  int A[n];
  for(int i=0;i<n;i++) cin>>A[i];
  
  int p = int((log10(n))/(log10(2.0)))+1;
  int size = 2*pow(2.0,p); // Size of segment tree = 2 * original number of elements in A for handling intervals.
  
  int M[size];
  for(int i=0;i<size;i++) M[i]=-1;  // M[i] is the position of minimum value in the interval assigned to node i.
  
  initialize(1,0,n-1,M,A);
  
  for(int i=0;i<size;i++) cout<<M[i]<<" ";
  
  int x,y,m;
  cin>>m;
  for(int i=0;i<m;i++){
          cout<<"Interval:- ";
          cin>>x>>y; // Find minimum element in the range [x,y] 
          int q = query(1,0,n-1,M,A,x,y);
          cout<<"Position of minimum element:- "<<q<<" and element:- "<<A[q]<<endl; // query returns position of the min element in [x,y]
  }
  
  A[2]=5;
  update(1,0,n-1,M,A,2);
  int q = query(1,0,n-1,M,A,2,3);
  cout<<"Position of minimum element:- "<<q<<" and element:- "<<A[q]<<endl;
  
  
  system("pause");
  return 0;
}
