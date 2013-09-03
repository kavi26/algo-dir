#include<iostream>
using namespace std;

int iterations = 0; // just to show that  complexity of solution is O(log(b))

long modular_exponentiation(long a, long b, long c){
 iterations++;
 
 if(b == 0)
  return 1;
 
 if(b % 2 == 0){
  long m = modular_exponentiation(a, b/2, c);
  return (m*m)%c;     
 }   
 
 if(b % 2 != 0){
  long m = modular_exponentiation(a, (b-1)/2, c);
  return (((m*m)%c )* (a % c)) % c;     
 }
}

int main()
{
  long exp = modular_exponentiation(70,1700, 9);
  cout<<exp<<endl;
  cout<<"iterations: " << iterations<<endl;

  system("pause");
  return 0;
}
