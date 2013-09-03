#include<iostream>
using namespace std;

// Floyd Warshall algorithm -- O(|V|^3) complexity
// Calculate all pair shortest paths

int main()
{
  int G[100][100]; // maximum no. of vertices 100
  memset(G, -1, sizeof(G));
  int V;
  cin >> V; // number of vertices
  int E;
  cin >> E;
  int m, n , wt;
  for(int i = 0; i < E; i++){
   cin >> m >> n >> wt;
   G[m-1][n-1] = wt;        
  }
  
  int dist[100][100]; // dist[i][j] gives shortest path between i and j
  memset(dist, 10000, sizeof(dist));
  
  for(int i = 0; i < V; i++) dist[i][i] = 0;
  
  for(int i = 0; i < V; i++)
   for(int j = 0; j < V; j++)
    if(G[i][j] != -1)
      dist[i][j] = G[i][j]; 
      
   for(int k = 0; k < V; k++)
    for(int i = 0; i < V; i++)
     for(int j = 0; j < V; j++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // The transitive closure: M(i, j) = M(i, k) * M(k, j)
      
   for(int i = 0; i < V; i++)
    cout << i+1 << " " << dist[1][i] << endl; // shortest distance from 2 to i+1
    
  
  system("pause");
  return 0;
}
