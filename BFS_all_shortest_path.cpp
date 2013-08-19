#include<iostream>
#include<algorithm>
#include<list>
#include "queue.h"
using namespace std;

const int n = 6;

void printAllPaths(list<int>*,int , int);
void BFS(bool [n][n], int*, int*, int,list<int>*, int );


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
   
   int source;
   cout<<"Enter source vertex: ";
   cin>>source;
   
   int query;
   cout<<"Enter the vertex whose shortest distance you want to find from source and also, its predecessor: ";
   cin>>query;
  
   
   //Print all path of length equal to shortest length from source to destination
   list<int> allPath[n];
   BFS(Graph, pred, shortest_distance, source-1, allPath, n);
   cout<<"Shortest distance of your query: "<<shortest_distance[query-1]<<endl;
   cout<<"Predecessor of your query: "<<pred[query-1]+1<<endl;
   
   printAllPaths(allPath,query-1,source-1);
   
   
   
    

  system("pause");
  return 0;
}

void printAllPaths(list<int>*allPath,int v, int source){
     
 if(v == source){
  cout<<v+1<<endl;    
  return; 
 }     
 cout<<v+1<<" ";
 list<int>::iterator it= allPath[v].begin();
 while(true){
   printAllPaths(allPath,*it,source);
   ++it;
   if(it == allPath[v].end()) break;
 }
 
}

void BFS(bool G[n][n], int*pred, int*shortDist, int source, list<int>*allPath, int num){ // n are number of vertices
     queue Q;
     Q.enqueue(source);
     shortDist[source] = 0;
     
     while(!Q.isEmpty()){
      int u = Q.dequeue();
      for(int i = 0; i<num; i++){
       if(G[u][i]){ // neighbour v = G[u][i] 
        if(shortDist[i] == -1){// vertex i is not yet visited
         allPath[i].push_back(u);
         shortDist[i] = shortDist[u] + 1;
         pred[i] = u;
         Q.enqueue(i);
         continue;
        }
        if(shortDist[i] == shortDist[u] + 1){ // if i is visited , then it's another path to reach vertex i.
         allPath[i].push_back(u);                
        }
       }        
      }                   
     }
     
}
