#include<iostream>
using namespace std;

/* Universal Sink Application:-
source: http://techinterviewsuncovered.blogspot.in/2008/12/universal-sink-problem-basic.html
The problem is that in a party of n people there is a celebrity whom everybody knows, and who does not know anybody. 
You can ask only this question to a guest in party "Do you know that guy x". Determine the celebrity. in least effort
*/

const int V = 5;

bool isSink(int G[V][V], int i){
 for(int j=0;j<V;j++)
  if(G[i][j] == 1) return false;
 
 for(int k=0;k<V;k++)
  if(G[k][i] == 0 && i != k) return false;
 
 return true;
}

int main()
{
  int G[V][V] = {0};
  int E;
  cin>>E;
  for(int i=0;i<E;i++){
   int m,n;
   cin>>m>>n;
   G[m-1][n-1] = 1;       
  }
  
  //Determing Universal Sink -- Time complexity O(V)
  int i = 0, j =0;
  while(i < V && j < V){
   if(G[i][j] == 1) i++;
   else j++;        
  }
  if(i == V){
   cout<<"There is no universal sink"<<endl;
  } else if(!isSink(G,i)){
     cout<<"There is no universal sink"<<endl;
    } else{
      cout<<"Universal Sink found: "<<i+1<<endl;       
    }
  
  
  
  system("pause");
  return 0;
}

