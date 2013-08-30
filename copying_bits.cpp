#include<iostream>
using namespace std;

/*
Two 32-bit integers n and m are given and positions i,j,k,l are given.Write a method to copy the contents of m from position k to l into n from position 
i to j. (example n=1010000,m=10101010,i=3,j=5,k=5,l=7..output=10'101'00)

Solution: use the logic of swapping two numbers using XOR.
*/

int main()
{
  int m = 170, n = 80;
  int i = 3, j = 5, k = 5, l = 7;
  unsigned int mask = ((m >> i) ^ (n >> k)) & (((1UL << l) - 1) >> (k-1));
  n = n ^ (mask << k);
  cout << n <<endl;
  

  system("pause");
  return 0;
}
