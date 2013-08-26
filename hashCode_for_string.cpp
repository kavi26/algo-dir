#include<iostream>
#include<cstring>
using namespace std;

//Hashing algorithm for strings -- Polynomial Accumulation -- converting each character into ASCII code and then
// making a polynomial with these codes as cofficients and value of x to be taken as prime like 31, 37, 41, etc. 
// Evaluate using Horner's rule

int calculate_hash(string s, int tableSize){
 int y = 0; // the hash code
 int len = s.length();
 int x = 31;
 for(int i = len-1; i >= 0; i--){
 y = (s[i] + x*y) % tableSize; // modulus is taken because integer limit is overflowed in a few characters    
 }    
 return y;   
}


int main()
{

  string s;
  cin >> s;
  cout << calculate_hash(s, 10000) << endl;
  
  system("pause");
  return 0;
}
