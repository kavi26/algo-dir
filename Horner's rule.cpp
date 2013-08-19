#include<iostream>
using namespace std;

int main()
{
  int size;
  cout<<"Size: ";
  cin >> size;
  int a[size];
  cout<<"Enter polynomial cofficients: ";
  for(int i = 0;i< size;i++){
   cin >> a[i];        
  }
  cout<<"Enter Value of evaluation x0: ";
  int x0;
  cin >> x0;
  
  int eval = 0;
  for(int i = size-1; i >= 0; i--) eval = a[i] + x0*eval;  //Horner's Rule of Polynomial Evaluation
  
  cout<<"Evaluated Polynomial Value: "<<eval<<endl;
  
  system("pause");
  return 0;
}
