#include<iostream>
#include<sstream>
#include<set>
using namespace std;

int G[100][100] = {0};
set<string> Set_Cycle;

string printCycle(int*parents, int n, int node, int start){ // start is the node which was already visited and lead to cycle
 ostringstream ss;
 ss << (node+1);
 
 if(node != start){
  string s = printCycle(parents, n, parents[node], start);      
  s += ss.str();
  return s;  
 }     
 
 if(node == start){
  return ss.str();       
 }
     
}

void printAllCycles(bool*visited, int*parents, int n, int node){
      
     visited[node] = true;
     for(int i = 0; i < n; i++){
      if(G[node][i]){ // i is neighbour of node
       if(!visited[i]){
        parents[i] = node;
        printAllCycles(visited, parents, n, i);
        }
       else{ // we have found a cycle
        int start = i;
        string cycle = printCycle(parents,n,node,start);
        string temp = cycle;
        sort(temp.begin(), temp.end());
        if(!Set_Cycle.count(temp)){
        Set_Cycle.insert(temp);
        cout << cycle;
        cout << start+1 << endl;
        //cout<<start+1 <<" " << node+1 <<  endl;
        }
       }  
      }       
     }   
     visited[node] = false;
}

int main()
{
  int n, m; // n is number of vertices, m is number of edges
  cin >> n;
  cin >> m;
  int source;
  for(int i = 0; i < m; i++){
   int a, b;
   cin >> a >> b;
   G[a-1][b-1] = 1;       
  }
  
  int parents[n];
  bool visited[n];
  
  for(int i = 0; i < n; i++)
  {
   parents[i] = -1;
   visited[i] = false;        
  }
  
  for(int i = 0; i < n; i++){
  if(!visited[i])
  printAllCycles(visited, parents, n, i);
  }

  system("pause");
  return 0;
}
