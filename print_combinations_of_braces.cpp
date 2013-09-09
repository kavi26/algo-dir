#include<iostream>
using namespace std;

/*
Write a function to generate all possible n pairs of balanced parentheses.

examples:
         
n=1
{}

n=2
{}{}
{{}}

for detailed solution:- http://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

O(2^n) complexity -- exponential 
*/

void printParenthesis(int pos, int n, int open, int close){
 static char str[200];
 if(close == n){
  printf("%s \n", str);
  return;         
 }     
 
 //Operation 1
 if(open > close){
  str[pos] = '}'; // add closing braces
  printParenthesis(pos+1, n, open, close+1);        
 }
 
 //Operation 2
 if(open < n){
  str[pos] = '{';
  printParenthesis(pos+1, n, open+1, close);        
 }
 
 /*
 Interchanging sequence of Operation 1 and Operation 2 (i.e. putting 2 before 1), the answer is same except the permutations are printed in
 reverse order of "{Operation 1 than operation 2} "
 
 Theme of solution: closing braces depends on opening braces and opening braces depends on n
 */
 
}

int main()
{
  int n;
  cin >> n;
  
  printParenthesis(0, n, 0, 0);
  

  system("pause");
  return 0;
}
