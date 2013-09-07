#include<iostream>
#include<set>
using namespace std;

/*
Given a list of integers, find out the biggest interval that has all its members in the given list.
 e.g. given list 1, 7, 4, 6, 3, 10, 2 then answer would be [1, 4], i.e. {1,2,3,4} are all present in given list and it is biggest interval 
 
 Solution: Simple solution using "set" to mark and count all contiguous elements.
*/

int main()
{
  set<int> S;
  int n;
  cout << "Enter Size of List: ";
  cin >> n;
  cout << "Enter the elements: ";
  for(int i = 0; i < n; i++)
  {
     int temp;
     cin >> temp;
     S.insert(temp);
  }
  
  int range[] = {0, -1};
   
  while(!S.empty()){
   int a = *(S.begin());
   S.erase(a);
   
   int i, j;
   for(j = a; !S.empty(); j--){
    if(!S.count(j-1))
     break;
    S.erase(j-1);     
   }    
   
   for(i = a; !S.empty(); i++){
    if(!S.count(i+1))
     break;
    S.erase(i+1);      
   }       
   
   if(i - j > range[1] - range[0]){
    range[0] = j;
    range[1] = i;     
   }
                      
  }
  
  cout << "Range is: [ " << range[0] << ", " << range[1] << " ]" << endl;
  
  
  system("pause");
  return 0;
}
