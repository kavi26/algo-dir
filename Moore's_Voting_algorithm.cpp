#include<iostream>
using namespace std;

//Moore's Voting algorithm for finding Majority element, if exists.
// Majority element is one which exists greater than n/2 times in given list of elements

//Good description: http://www.geeksforgeeks.org/majority-element/
int MooreVoting(int*A, int size){
    
 int major_index = 0, count = 1;
 
 for(int i = 1; i < size; i++){
  if(A[major_index] == A[i])
   count++;
  else 
   count--;
  
  if(count == 0){
   major_index = i;
   count = 1;         
  }             
 }    
  
 return A[major_index];  
}

bool isMajorityElem(int*A, int size, int elem){
 int count = 0;
 for(int i = 0; i < size; i++)
  if(A[i] == elem) count++;
  
 if(count > size/2) return true;
 return false;     
}


int main()
{
  int A[] = {2, 2, 3, 5, 2, 2, 6};
  int majorityElement = MooreVoting(A,7);
  if(isMajorityElem(A, 7, majorityElement))
   cout<<"Majority element exists: " << majorityElement << endl;
  else
   cout<<"No Majority element exists !" <<endl;
  
  system("pause");
  return 0;
}
