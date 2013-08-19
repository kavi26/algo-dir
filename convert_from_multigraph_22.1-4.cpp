#include<iostream>
#include<istream>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
  list<int> adj[3];
  list<int> auxArray[3];
  list<int> adjnew[3];
  //cout<<adjnew[2].back()<<endl;
  
  for(int i = 0;i<3;i++){
   int x;
   while(true){ // reading a line of integers until new line is encountered , peek() returns the next input character without extracting it.
    scanf("%d",&x);                               
    adj[i].push_back(x); 
    auxArray[i].push_back(x);
    if(cin.peek() == '\n') break;                                             
   }        
  }
  
  //flatten the adj-list
  for(int i = 0;i<3;i++){
   list<int>::iterator it = adj[i].begin();
   while(it != adj[i].end()){
    auxArray[*it].push_back(i);
    it++;
   }
  }
  
  
  for(int i = 0;i<3;i++){
   list<int>::iterator it = auxArray[i].begin();
   while(it != auxArray[i].end()){
    //cout<<*it<<" "<<adjNew[*it].back()<<endl;
    if((*it != i) && ((adjnew[*it].back()) != i)){
    // cout<<*it<<" -> "<<i<<endl;
     adjnew[*it].push_back(i);         
     }
     it++;
   }
  }
  
  for(int i = 0;i<3;i++){
   list<int>::iterator it = adjnew[i].begin();
   while(it != adjnew[i].end()){
     cout<<*it<<" ";  
     it++;       
   }
   cout<<endl;
  }

 
  system("pause");
  return 0;
}
