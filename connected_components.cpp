#include<iostream>
#include<algorithm>
#include "queue.h"
using namespace std;

const int n = 6;

void BFS(bool [n][n], int*, int*, int,int*,int, int );

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
   
   //Determining connected components and their labels, so that given 2 vertices, we can decide in constant time whether they belong to
   // same connected component or not.
   
   int labels[n];
   memset(labels,0,sizeof(labels));
   
   
   int components = 0;
   
   for(int i = 0; i < n; i++){
   if(labels[i] == 0){
   components++;
   BFS(Graph, pred, shortest_distance, i, labels,components,n);
   
   }
   }
   
   for(int i = 0; i < n; i++) cout<<i+1<<" "<<labels[i]<<endl;
   cout<<"Components: "<<components<<endl;
   
   //Complexity: O(m+n) as number of edges can be 0
   
 
  system("pause");
  return 0;
}

void BFS(bool G[n][n], int*pred, int*shortDist, int source, int*labels,int component, int n){ // n are number of vertices
     queue Q;
     Q.enqueue(source);
     shortDist[source] = 0;
     
     while(!Q.isEmpty()){
      int u = Q.dequeue();
      labels[u] = component; // label vertices with the current component number
      for(int i = 0; i<n; i++){
       if(G[u][i] && shortDist[i] == -1){ // neighbour v = G[u][i] & vertex i is not yet visited
         shortDist[i] = shortDist[u] + 1;
         pred[i] = u;
         Q.enqueue(i);
       }        
      }                   
     }
     
}
