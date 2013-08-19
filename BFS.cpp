#include<iostream>
#include<algorithm>
#include "queue.h"
using namespace std;

void BFS(bool [6][6], int*, int*, int, int );

int main()
{
  bool Graph[6][6];
  for(int i = 0;i<6;i++)
   for(int j = 0;j<6;j++) Graph[i][j] = false;

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
   int pred[6]; // predecessor array of vertices 
   int shortest_distance[6];  //shortest distance of each vertex from source vertex and also shows if the vertex has been visited or not.
   for(int i = 0;i<6;i++) shortest_distance[i] = -1;
   
   int source;
   cout<<"Enter source vertex: ";
   cin>>source;
   BFS(Graph, pred, shortest_distance, source-1, 6);
   
   int query;
   cout<<"Enter the vertex whose shortest distance you want to find from source and also, its predecessor: ";
   cin>>query;
   
   cout<<"Shortest distance of your query: "<<shortest_distance[query-1]<<endl;
   cout<<"Predecessor of your query: "<<pred[query-1]+1<<endl;
   
   //Printing one shortest path
   cout<<"Shortest Path is: "<<endl;
   string path = "";
   int temp = query - 1;
   char* x;
   while(temp != source-1){
    itoa(temp+1,x,10);
    path += string(x) + " ";
    temp = pred[temp];
   }
   itoa(temp+1,x,10);
   path += x;
   reverse(path.begin(), path.end());
   cout<<path<<endl; // path is printed from source to destination
   
  system("pause");
  return 0;
}

void BFS(bool G[6][6], int*pred, int*shortDist, int source, int n){ // n are number of vertices
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
       }        
      }                   
     }
     
}
