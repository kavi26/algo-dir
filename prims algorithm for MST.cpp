#include "MSTheap.h"
#include<iostream>
#include<vector>
using namespace std;

struct node{
 int v; // vertex in the node
 int edge; // edge length to this vertex
};


int main()
{
  int V; // number of vertices
  cin>>V;
  vector<node> G[V]; //Undirected Graph
  
  int E; // Number of edges
  cin>>E;
  
  for(int i=0; i<E; i++){
   int m,n,e;
   cin>>m>>n>>e; // edge between m and n with edge length "e"
   node temp;
   temp.v = n-1;
   temp.edge = e;
   G[m-1].push_back(temp);
  }
  
  //Initialising S[V], the set containing vertex which have been already encountered
  bool S[V];
  memset(S,0,sizeof(bool)); // initializing all vertices to be present in S-complement set.
  minHeap H; // Heap only contains vertices indices which changes during heap operations
 // int label[V]; // label[w] contains the label of vertice w and its position don't change, only its value is updated.
  
  for(int i = 0; i < V; i++){
    H.insert(i); // Insert vertices in Heap array
    H.setLabel(i,INT_MAX); // insert labels in heap's label[]
  }
  
  H.decrPrior(0,0); // i = root = 0, key = priority of root = 0. priority value is stored in label
  while(!H.isEmpty()){
   int v = H.extractMin();
   for(vector<node>::iterator it = G[v].begin(); it != G[v].end(); it++){
     if(S[it->v] == 0){ // (w = it->v) is not in set S  
      S[it->v] = 1; 
      if(H.getLabel(it->v) > it->edge){
       H.setLabel(it->v, it->edge);
       H.decrPrior(it->v,it->edge);
      }
     }                        
   }                    
  }
  
  
   
  system("pause");
  return 0;
}
