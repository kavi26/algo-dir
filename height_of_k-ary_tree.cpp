#include<iostream>
using namespace std;

/*
Problem Description :-

Given an array which contains the parent of the ith element in the n-ary tree.Parent[i] = -1 for root. 
Find the height of the tree. 
Example- 
{-1 0 1 6 6 0 0 2 7} 
0 1 2 3 4 5 6 7 8 
0 is the root here. 
0 is the parent of 1 5 6 
1 is parnt of 2 
6 is parent of 3 4 
2 is of 7 which is parent of 8.


Solution:- Keep an additional array b[n] storing the levels of all elements, i.e. b[i] = b[a[i]] + 1 -> level of a node is one
           more than its parent(a[i]).
*/

void level(int*a, int*b, int i){
 if(a[i] == -1) b[i] = 0; // i.e. 'i' is the root
 else if(b[a[i]] != -1) b[i] = b[a[i]] + 1;
 else{ // level of parent of 'i', i.e. a[i] is not determined
 level(a,b,a[i]); // determine the level of parent of i
 b[i] = b[a[i]] + 1;
 }     
}

int main()
{

  int n;
  cin>>n; // number of nodes in n-ary tree
  
  int a[n]; // parent storing array
  int b[n];
  
  for(int i = 0; i < n; i++){
   b[i] = -1;
   cin >> a[i];        
  }

  for(int i = 0; i < n; i++)
   if(b[i] == -1)
    level(a,b,i);

 int j = INT_MIN;
 for(int i = 0; i < n; i++)
  j = max(b[i], j);
  
 cout<<"Height: "<<j+1<<endl;

  system("pause");
  return 0;
}
