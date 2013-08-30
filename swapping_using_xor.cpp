#include<iostream>
using namespace std;

//Swapping two numbers using XOR without using extra variable

int main()
{
  int a, b;
  cin >> a >> b;
  a = a^b;
  b = a^b;
  a = a^b;
  cout<<a<< " " << b;

  system("pause");
  return 0;
}
