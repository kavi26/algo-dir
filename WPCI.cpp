#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 1000;

/*
This program prints the lexicographically smallest permutation given only certain positions can swap.
*/

vector<int> A;
vector<int> G[MAXN];
vector<int> connected; // contains the indices which are in same connected component during a DFS in a connected component and cleared after 1 DFS.
vector<int> positions; // contains the corresponding elements of indices in vector "connected".

void DFS(int*visited, int u){
      visited[u] = 1;
      connected.push_back(u);
      for(int i = 0; i < G[u].size(); i++){
       if(!visited[G[u][i]])        
        DFS(visited,G[u][i]);
      } 
}

int main()
{
  int T;
  cin>>T; // Number of test cases
  for(int t = 0; t < T; t++){
   int n, m;
   cin>>n>>m; // positions which can be swapped
   for(int i = 0; i < n; i++){
    int x;
    cin>>x; // the given array of integers
    A.push_back(x);        
   }
   int x, y;
   for(int i = 0; i < m; i++){
    cin>>x>>y;
    G[x-1].push_back(y-1); // problem is modelled in graph.
    G[y-1].push_back(x-1);
   }   
   
   int visited[MAXN] = {0};
   for(int i = 0; i < n; i++){
    if(!visited[i]){
     DFS(visited,i);
     for(int j = 0; j < connected.size(); j++){
      positions.push_back(A[connected[j]]);        
     }
     sort(connected.begin(), connected.end());
     sort(positions.begin(), positions.end());
     for(int j = 0; j < connected.size(); j++){
      A[connected[j]] = positions[j];        
     }
     connected.clear();
     positions.clear();
    }     // if(!visited[i]) ends  
           
   } // for loop ends
   
   for(int p = 0; p < n; p++) cout<<A[p]<<" ";
   cout<<endl;       
   
   A.clear();
   for(int i = 0; i < MAXN; i++) G[i].clear();
          
  } // loop for "T" ends
 
 
 system("pause");
  return 0;
}
