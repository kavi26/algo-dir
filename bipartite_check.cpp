#include<iostream>
#include<algorithm>
#include "queue.h"
using namespace std;

const int n = 6;

bool BFS(bool [n][n], int*, int*, int, int );

int main()
{
  bool Graph[n][n];
  for(int i = 0;i<n;i++)
   for(int j = 0;j<n;j++) Graph[i][j] = false;

  //Input Graph
  cout<<"Input Graph: "<<endl;
  cout<<"Number of edges: ";
  int edges;
  cin>>edges;
  for(int i = 0; i < edges ; i++)
    {
      int m, n; // edge from m to n
      cin>>m>>n;
      Graph[m-1][n-1] = true;   
    }
   int pred[n]; // predecessor array of vertices 
   int shortest_distance[n];  //shortest distance of each vertex from source vertex and also shows if the vertex has been visited or not.
   for(int i = 0;i<n;i++) shortest_distance[i] = -1;
   
   // A graph is bipartite if it can be partitioned into two subsets U and W such that all edges have one end in one of the subset and 
   // other end in the other subset. Choosing alternate levels of vertices in BFS, if there is no edge within any of the level(which make an odd cycle)
   // gives us bipartition. If during BFS, we encounter two adjacent vertices in same level, it has an odd cycle and hence non-bipartite.
   bool isBiPartite = BFS(Graph, pred, shortest_distance,0, n);
   if(isBiPartite){
    // Print the two partition
    cout<<"Set U"<<"   "<<"Set W"<<endl;
    for(int i=0;i < n;i++){
     if(shortest_distance[i]%2 == 0) cout<<" "<<i+1<<endl;
     else cout<<"            "<<i+1<<endl;
    }
   }else cout<<"Graph is not bipartite"<<endl;
         
   
  system("pause");
  return 0;
}

bool BFS(bool G[n][n], int*pred, int*shortDist, int source, int n){ // n are number of vertices
     queue Q;
     Q.enqueue(source);
     shortDist[source] = 0;
     
     while(!Q.isEmpty()){
      int u = Q.dequeue();
      for(int i = 0; i<n; i++){
       if(G[u][i] && shortDist[i] == -1){ // neighbour v = G[u][i] & vertex i is not yet visited
         shortDist[i] = shortDist[u] + 1;
         pred[i] = u;
         Q.enqueue(i);
       }else if(G[u][i] && shortDist[i] == shortDist[u]) {
             cout<<i+1<<" and "<<u+1<<" are on same level and hence form an odd cycle "<<endl;
             return false;  // both i and u have same labels
       }
      }                   
     }
  return true;
}
