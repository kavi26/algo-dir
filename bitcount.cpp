#include<iostream>
using namespace std;

int bitcount(int n){ // count number of 1's in bit representation of n
  int ans = 0;
  while(n != 0){
   if(n & 1) ans++;
   n >>= 1;
  }
  return ans;
}

// n & ~(n - 1) gives the first bit which is set

int main()
{
   cout<<bitcount(16)<<endl;

  system("pause");
  return 0;
}
