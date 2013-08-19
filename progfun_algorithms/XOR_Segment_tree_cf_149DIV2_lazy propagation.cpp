/**************Segment tree with lazy propagation. For lazy propagation see:- http://www.spoj.pl/forum/viewtopic.php?f=27&t=8296**************/

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

#define size 400005

long long M[20][size],lazy[20][size]={0}; // lazy propagation gives O(logn) time for updating and querying.

// [b,e] are intervals represented by "node"
void initialize(int node,int b,int e,int*A,int i){// i'th column tree is initialized
     if(b==e){ 
              M[i][node]= ((A[b]>>i)&1); // (x>>i)&1 returns i'th bit from right in binary representation.e.g. 13=1101, (13>>1)&1 will give 0.
              return;
     }
     
     initialize(2*node,b,(b+e)/2,A,i);
     initialize(2*node+1,(b+e)/2+1,e,A,i);
     
     M[i][node] = M[i][2*node] + M[i][2*node+1];
}

/****** In lazy propagation, we update a node if we pass a node whose flag(lazy[i][node]) is set, whether it's update operation or querying.*****/
/********* VERY CLEARLY EXPLAINED IN "http://www.spoj.pl/forum/viewtopic.php?f=27&t=8296" *****************************************************/
long long query(int node,int b,int e,int l,int r,int i){
    if(lazy[i][node]){ // If the flag bit of current node is set than update the node, set children if exists,reset the flag of current node.
                      M[i][node]= e-b+1-M[i][node];
                      if(b != e){
                           lazy[i][2*node] ^= 1;
                           lazy[i][2*node+1] ^= 1;
                      }
                      lazy[i][node] = 0;
    }
                           
    if(r<b || l>e) return 0;
    if(l<=b && r>=e) return M[i][node];
    
    return query(2*node,b,(b+e)/2,l,r,i) + query(2*node+1,(b+e)/2+1,e,l,r,i);
}

void update(int node,int b,int e,int l,int r,int i){
     if(lazy[i][node]){
                      M[i][node]= e-b+1-M[i][node];
                      if(b != e){
                           lazy[i][2*node] ^= 1;
                           lazy[i][2*node+1] ^= 1;
                      }
                      lazy[i][node] = 0;
    } 
    if(r<b || l>e) return;
     if( b>=l && e<=r){
              M[i][node] = e-b+1- M[i][node];
              if(b != e){
                           lazy[i][2*node] ^= 1;
                           lazy[i][2*node+1] ^= 1;
              }
              lazy[i][node] = 0;
              return;
     }
     
     
     update(2*node,b,(b+e)/2,l,r,i);
     update(2*node+1,(b+e)/2+1,e,l,r,i);
     M[i][node] = M[i][2*node] + M[i][2*node+1];
     
     return; 
}
     
  


int main()
{  
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++) cin>>A[i];
  
  for(int i=0;i<20;i++) initialize(1,0,n-1,A,i); //Initialize all 20 bit-segment trees(M[20]) acc. to tutorial given.http://codeforces.ru/blog/entry/5837
  
  int m;
  cin>>m;
  int t,l,r,x;
  for(int i=0;i<m;i++){
          cin>>t;
          if(t==1){ // Query of Sum
                   cin>>l>>r;
                   long long sum = 0;
                   for(int i=0;i<20;i++) sum += query(1,0,n-1,l-1,r-1,i)<<i; // Equivalent to sum += pow(query,pow(2.0,i));
                   cout<<sum<<endl;
          }
          if(t==2){ // update elements in range [l,r]
                   cin>>l>>r>>x;
                   for(int i=0;i<20;i++) if(((x>>i)&1)==1) update(1,0,n-1,l-1,r-1,i); // reverse 0->1 & 1->0 in i'th column.
          }
  }  

  system("pause");
  return 0;
}
