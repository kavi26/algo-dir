#include<iostream>
#include<cmath>
using namespace std;

void factorize_Trial_Division(int n){
 for(int i = 2; i <= (int)sqrt(n); i++){
  while(n % i == 0){
   cout << i << " ";
   n /= i;        
  }
 }     
 if(n > 1) cout << n << endl;    
}

int main()
{
  factorize_Trial_Division(1020);

  system("pause");
  return 0;
}
