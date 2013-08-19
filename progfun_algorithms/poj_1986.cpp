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

void preprocess(int*L,int n){  // For RMQ
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

void DFS(vector< pair<int,int> >*T,int*E,int*L,int*H,int*level,int b,int n,int*distance){ // For LCA
    // b is k+1'th visited node
    E[k+1]=b;
    level[b] = (k==0) ? 0 : (L[k]+1);// if b is root its level = 0; else its level = level of previous visited node+1.
    H[b] = k+1; // first occurence of b is at k+1'th position.
    L[k+1]=level[b];
    k++;
    
    for(int i=0;i<T[b].size();i++){
            if(level[T[b][i].first]==-1)// first occurence of node T[b][i]
            { distance[T[b][i].first] =  (distance[b]+T[b][i].second);
              DFS(T,E,L,H,level,T[b][i].first,n,distance);
              k++;
              E[k]=b;
              L[k]=level[b];
              }
    }                  
    
}



int main()
{
  //Initialise a tree.
  int n,m; 
  cin>>n>>m;
  vector< pair<int,int> > T[n+1];
  int x,y,a;
  char b;
  for(int i=0;i<m;i++){
          cin>>x>>y>>a;
          cin>>b;
          T[x].push_back(make_pair(y,a));
          T[y].push_back(make_pair(x,a));
  }
  
  int E[2*n]; // Total number of visits is 2*n-1 & E[i] stores i'th visited  node in the tour.
  int L[2*n]; // L[i] stores level of i'th visited node in tour,i.e. level of E[i]
  int H[n+1]; // H[i] stores the index of first occurence of node "i" in array E. 
  int level[n+1];//It decides whether the node has been visited or not using sentinel value of -1.
  for(int i=0;i<=n;i++) level[i]=-1; // i'th node hasn't been visited
  
  int distance[n+1]; // distance[i] will give the distance of node i from node 1. i.e. we are doing Dijkstra Algorithm in Tree given.
                     // Since a tree has only one path between 2 nodes, we can perform Dijkstra Algorithm using a DFS alone.
  
  k = 0;
  distance[1]=0;
  DFS(T,E,L,H,level,1,n,distance);
  
  preprocess(L,2*n);
  
  int w;
  cin>>w;
  for(int i=0;i<w;i++){
          int LCA;
          cin>>x>>y;
          int p=H[x],q=H[y];
          if(p>q) swap(p,q);
          int t = int((log10(q-p+1))/(log10(2.0)));
          if(L[M[p][t]]<=L[M[q+1-(1<<t)][t]])
              LCA=E[M[p][t]];
          else
              LCA=E[M[q+1-(1<<t)][t]];
              
          cout<<(distance[x]-distance[LCA])+(distance[y]-distance[LCA])<<endl;
  }
  
  
          

  system("pause");
  return 0;
}
