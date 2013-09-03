#include<iostream>
#include<vector>
using namespace std;

//Bellman Ford Algorithm -- for finding single source shortest paths (including (-)ve edges in O(|V| * |E|) time)



int main()
{ 
  int V;
  cout << "V: ";  //Number of vertices
  cin >> V;
  
  vector<pair<int, int> > G[V]; // Weighted Directed Graph
  
  int E; // Number of Edges
  cout << "E: ";
  cin >> E;
  
  for(int i = 0; i < E; i++){
   int m,n, wt; // wt is weight
   cin >> m >> n >> wt;
   pair<int, int> temp(n-1, wt);
   G[m-1].push_back(temp);
  }
  
  int d[V];
  memset(d, 10000, sizeof(d)); // maximum distance 10000
  
  int source;
  cout << "source: ";
  cin >> source;
  
  d[source-1] = 0; // This is the checkpoint as the source must be set to 0 for algorithm to run perfectly, otherwise there is no aim of algorithm
  
  cout<<"labels after 0'th iteration: " << endl;
  for(int v = 0; v < V; v++)
   cout << v+1 << "  " << d[v] << endl;
  
  for(int i = 1; i < V; i++){ // loop must run (V-1) times
   for(int v = 0; v < V; v++) // for all vertices in each loop
    for(int w = 0; w < G[v].size(); w++) // for all neighbour's of v
     d[G[v][w].first] = min(d[G[v][w].first], d[v]+ (G[v][w]).second);
  
  cout<<"labels after iteration " << i <<": " << endl;
  for(int v = 0; v < V; v++)
   cout << v+1 << "  " << d[v] << endl;
  
  }
  
  cout << "Distances of all vertices from source "<<source << ": " <<endl;
  for(int i = 0; i < V; i++)
   cout << i+1 << "  " << d[i] << endl;

  system("pause");
  return 0;
}
