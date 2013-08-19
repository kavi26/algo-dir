#include<iostream>
using namespace std;

const int V = 5;

void DFS(int [V][V], int*,int*,int*, int, int*);

int main()
{
  int G[V][V] = {0};
  int E;
  cin>>E;
  for(int i = 0;i<E;i++){
   int m, n;
   cin>>m>>n;
   G[m-1][n-1] = G[n-1][m-1] = 1;  // Undirected Graph   
  }
  
  int visited[V] = {0};
  int arr[V]; // arrival time
  int dep[V]; // departure time
  
  int source;
  cout<<"Source Vertex: ";
  cin>>source;
  
  int time = 0; // time stamp to measure arrival and departure time -- time stamp increases while entering a node and while departing it permanently.
  DFS(G,arr,dep,visited,source-1,&time);
  
  for(int i =0;i<V;i++) cout<<arr[i]<<" ";
  cout<<endl;
  
  for(int i =0;i<V;i++) cout<<dep[i]<<" ";
  cout<<endl;
  
  
  system("pause");
  return 0;
}

void DFS(int G[V][V], int*arr,int*dep,int*visited,int source, int*time){
 visited[source] = 1;
 (*time)++;
 arr[source] = *time;
 for(int i = 0;i<V;i++){
  if(G[source][i] && !visited[i])
   DFS(G,arr,dep,visited,i,time);
 }
 
 (*time)++;
 dep[source] = *time;
}
