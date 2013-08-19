/**********Based on the tutorial:- http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor#Segment_Trees*********/

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

int M[MAXN][64];

void preprocess(int*L,int n){
     int i,j;
     
     for(i=1;i<n;i++)
      M[i][0] = i;
     
     for(j=1;(1<<j)<=n;j++)
       for(i=1;i<n;i++)
         if(L[M[i][j-1]]<=L[M[i+(1<<(j-1))][j-1]])
          M[i][j] = M[i][j-1];
         else
          M[i][j]=M[i+(1<<(j-1))][j-1];
}

static int k = 0;

void DFS(vector<int>*T,int*E,int*L,int*H,int*level,int b,int n){
    // b is k+1'th visited node
    E[k+1]=b;
    level[b] = (k==0) ? 0 : (L[k]+1);// if b is root its level = 0; else its level = level of previous visited node+1.
    H[b] = k+1; // first occurence of b is at k+1'th position.
    L[k+1]=level[b];
    k++;
    
    for(int i=0;i<T[b].size();i++){
            if(level[T[b][i]]==-1)// first occurence of node T[b][i]
            {
              DFS(T,E,L,H,level,T[b][i],n);
              k++;
              E[k]=b;
              L[k]=level[b];
              }
    }                  
    
}




int main()
{
  //Initialise a tree.
  cout<<"Number of nodes:- ";
  int n; 
  cin>>n;
  vector<int> T[n+1];
  int x,y;
  for(int i=0;i<n-1;i++){
          cin>>x>>y;
          T[x].push_back(y);
          T[y].push_back(x);
  }
  //Now initialize 3 arrays giving info of Euler tour(each leaf node is visited once & internal node thrice in an euler tour) as given in topcoder tutorial
  
  int E[2*n]; // Total number of visits is 2*n-1 & E[i] stores i'th visited  node in the tour.
  int L[2*n]; // L[i] stores level of i'th visited node in tour,i.e. level of E[i]
  int H[n+1]; // H[i] stores the index of first occurence of node "i" in array E. 
  int level[n+1];//It decides whether the node has been visited or not using sentinel value of -1.
  for(int i=0;i<=n;i++) level[i]=-1; // i'th node hasn't been visited
  
  k = 0;
  
  DFS(T,E,L,H,level,1,n);
  
  /*
  cout<<"Array E[i]: ";
  for(int i=0;i<2*n;i++) cout<<E[i]<<" ";
  cout<<endl;
  cout<<"Array L[i]: ";
  for(int i=0;i<2*n;i++) cout<<L[i]<<" ";
  cout<<endl;
  cout<<"Array H[i]: ";
  for(int i=0;i<=n;i++) cout<<H[i]<<" ";
  cout<<endl;
  cout<<"Array level[i]: ";
  for(int i=0;i<=n;i++) cout<<level[i]<<" ";
  cout<<endl;
  */
  
  cout<<"Enter the numbers whose LCA is to be find out:- ";
  cin>>x>>y;
  
  // NOW LCA = E[RMQ_IN_L(H[x],H[y])] according to tutorial given
  
  preprocess(L,2*n);
  
  
    int p=H[x],q=H[y];
    if(p>q) swap(p,q);
    int t = int((log10(q-p+1))/(log10(2.0)));
    if(L[M[p][t]]<=L[M[q+1-(1<<t)][t]])
     cout<<"LCA: "<<E[M[p][t]]<<endl;
    else
     cout<<"LCA: "<<E[M[q+1-(1<<t)][t]]<<endl;
  
  
  
  
  
  system("pause");
  return 0;
}
