#include<iostream>
using namespace std;

const int V = 7;

//twoEC -- 2-edge connected

int twoEC(int [V][V], int*,int*,int*,int*, int,int, int*); // returns the deepest back edge

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
  int pred[V] = {-1}; // predecessor
  
  int source;
  cout<<"Source Vertex: ";
  cin>>source;
  
  int root = source-1; // just for checking dbe is upto root or not in twoEC function.
  
  int time = 0; // time stamp to measure arrival and departure time -- time stamp increases while entering a node and while departing it permanently.
  int dbe = twoEC(G,arr,dep,visited,pred,source-1,root,&time);
  
  for(int i =0;i<V;i++) cout<<arr[i]<<" ";
  cout<<endl;
  
  for(int i =0;i<V;i++) cout<<dep[i]<<" ";
  cout<<endl;
  
  
  system("pause");
  return 0;
}

//try to find deepest back-edge and check whether it is above current vertex's arrival time or not.

int twoEC(int G[V][V], int*arr,int*dep,int*visited,int*pred,int source,int root, int*time){ 
 visited[source] = 1;
 (*time)++;
 arr[source] = *time;
 int dbe = arr[source]; // let the deepest back edge from descendents of source be upto source(just initialised). 
 // dbe should not be the edge from parent to current vertex, i.e. through which current vertex has been reached from its parent.
 for(int i = 0;i<V;i++){
  if(G[source][i] && !visited[i]){
   pred[i] = source;
   dbe = min(dbe,twoEC(G,arr,dep,visited,pred,i,root,time));
  }
  else if(G[source][i] && i != pred[source]) // i.e. the neighbour of source, i.e. i, which is visited should not be its parent.
       dbe = min(dbe, arr[i]);
 }
 
 (*time)++;
 dep[source] = *time;
 
 if(dbe < arr[source]) return dbe;
 else if(dbe == arr[source] && source == root) return dbe;
 else {
  cout<<"G is not 2-edge connected"<<endl;
  if(source != root) cout<<"Bridge: "<<source+1<<" "<<pred[source]+1<<endl;
  return dbe;     
 }

}
