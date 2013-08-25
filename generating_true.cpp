#include<iostream>
using namespace std;

// given an integer x, generate true with probability x/100.


int main()
{
  int x;
  cin>>x;
  
  int y = rand()%100;
  if(y <= x) // each number is equally like between 1 and 100. So, the probability of occuring a number is 1/100.
   cout<<true<<endl;
  else 
   cout<<false<<endl;
  
  system("pause");
  return 0;
}
