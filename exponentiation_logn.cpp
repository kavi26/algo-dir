#include<iostream>
using namespace std;

int exponentiation(int a, int b){
 if(b == 0)
  return 1;
 
 if(b % 2 == 0){
  int c = exponentiation(a, b/2);
  return c*c;     
 }   
 
 if(b % 2 != 0){
  int c = exponentiation(a, (b-1)/2) ;
  return c*c*a;     
 }
}

int main()
{
  int exp = exponentiation(3,7);
  cout<<exp<<endl;

  system("pause");
  return 0;
}
