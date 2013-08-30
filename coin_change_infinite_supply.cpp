#include<iostream>
using namespace std;

/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.

Solution: Simple dp problem. Use an array table[n], where table[i] stores number of ways to make "i" using given coins.
and the relation that, number of ways to form table[i] = (forming table[i-S[0]] and then table[i] by adding S[0]) + (forming table[i-S[1]] ...) + .... so on

Space complexity -- O(n)
Time Complexity -- O(m*n)

For good explanation: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
*/

int countWays(int*S, int m, int n ){
 int table[n+1];
 memset(table, 0 , sizeof(table));
 table[0] = 1; // number of ways to form 0 is 1
 
 for(int i = 0; i < m; i++)
  for(int j = S[i]; j <= n; j++)
   table[j] += table[j-S[i]];
   
 return table[n];     
}

int main()
{

  int coins[] = {2,5,3,6};
  int amount = 10;
  cout<<countWays(coins, 4, amount ) << endl; 

  system("pause");
  return 0;
}
