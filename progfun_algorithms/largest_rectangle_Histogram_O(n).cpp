#include<iostream>
#include<stack>
using namespace std;

/*
 Problem Statement: http://www.informatik.uni-ulm.de/acm/Locals/2003/html/histogram.html
 Largest Rectangle in Histogram
 Time Complexity: O(n)
*/

int MaxAreaRect(int*, int);

int main()
{
  int H[7] = {6, 2, 5, 4, 5, 1, 6};
  cout<<"Maximum Area: " << MaxAreaRect(H,7)<<endl;;
  
  system("pause");
  return 0;
}

int MaxAreaRect(int*Hist, int n){
    
 stack<int> s; // s stores index of bars, and all bars with index in s are in increasing order.
 int max_area = INT_MIN;
 int area_from_top; //to store area with top bar as smallest bar
 int tp; // To store top of stack
 
 int i = 0;
 while(i < n){
  if(s.empty() || Hist[s.top()] <= Hist[i])
   s.push(i++);
   
  else{
   tp = s.top();
   s.pop();
   
   area_from_top = Hist[tp] * (s.empty()? i : i - s.top() - 1);
   
   if(area_from_top > max_area)
    max_area = area_from_top;     
  }      
 }
 
 while(!s.empty()){
  tp = s.top();
  s.pop();

  area_from_top = Hist[tp] * (s.empty()? i : i - s.top() - 1);
   
  if(area_from_top > max_area)
   max_area = area_from_top;                            
 }
    
 return max_area;
}
