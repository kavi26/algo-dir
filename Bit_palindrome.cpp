#include<iostream>
#include<cmath>
using namespace std;

bool isBitPalindrome(int num){
  int reverse_num = 0; // contains the bits of num in reverse order
  int temp = num;
  while(temp != 0){
   reverse_num <<= 1;
   if(temp & 1){
    reverse_num |= 1;        
   }   
   temp >>= 1; 
  }
  if(reverse_num == num)
   return true;
  else
   return false;
}

int main()
{
  int m;
  cin >> m;
  //Determining Bit Palindrome or not
  cout << ((isBitPalindrome(m)) ? "Is Bit Palindrome" : "Not a Bit Palindrome") << endl;
  
  if((double)((int)sqrt(m)) - sqrt(m) == 0.0) 
   cout << "Perfect Square" << endl;
  else
   cout << "Not Perfect Square" << endl;
   
  double temp = log10(m)/log10(2.0); // log2(m)
  if((double)((int)temp) - temp == 0 )
   cout <<"Power of 2, and the exponent is: " << (int)temp << endl;
  else
   cout <<"Not Power of 2" << endl;

  system("pause");
  return 0;
}
