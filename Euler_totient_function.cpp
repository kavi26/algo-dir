#include<iostream>
#include<cmath>
using namespace std;

// http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=primeNumbers
// Calculate number of positive integers before n that are coprime to n
int Euler_totient_function(int n){
 int m = (int)sqrt(n);
 int result = n;
 for(int i = 2; i <= m; i++){
  if(n % i == 0) result -= result / i;
  while(n % i == 0) n /= i;
 } 
  if(n > 1) result -= result / n;
  return result;
}

int main()
{
  cout << Euler_totient_function(20) <<endl;

  system("pause");
  return 0;
}
