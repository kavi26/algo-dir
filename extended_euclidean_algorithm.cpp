#include<iostream>
using namespace std;

//Solving equations of the form a*x + b*y = d for integral values of x and y
// Using Extended Euclidean Algorithm --  if the gcd(a, b) don't divide d then there are no integral solutions !!
// so, we find the solution for a*x + b*y = gcd(a, b) and then actual solution would be multiplying (x,y) by (d / gcd(a, b))
// the general solution is (x + (k*b)/gcd(a, b) , y - (k*a)/gcd(a, b))

// A good resource can be: http://www.youtube.com/watch?v=uTFuHRK5Pmk

pair<int, int> extended_Euclidean_algorithm(int a, int b){
 if(b == 0){
  pair<int, int> p(1, 0);
  cout << "GCD: " << a << endl;
  return p;     
 } 
 int q = a / b;
 int r = a % b;
 pair<int, int> s = extended_Euclidean_algorithm(b, r); 
 
 pair<int, int> solution(s.second, s.first - q * s.second);
 return solution;
}

int main()
{
  int a,b; //a*x + b*y = gcd(a, b)
  cin >> a >> b;
  pair<int, int> solution = extended_Euclidean_algorithm(a, b);
  cout<<solution.first << " " << solution.second << endl; 

  system("pause");
  return 0;
}
