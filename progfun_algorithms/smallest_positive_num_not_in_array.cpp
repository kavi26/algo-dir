#include<iostream>
#include<set>
using namespace std;

/*
Smallest positive number not present in array using Hashing
Time Complexity: O(n) , space complexity: O(n)
Using set to store all positive values
or using hash in #include<functional> library
*/
int main()
{
  int n;
  cin >> n;
  
  set<long long> s;
  long long x;
  
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x > 0)
    s.insert(x);       
  }
  
  int ans = 1;
  while(true)
  {
   if(!s.count(ans))
    break;           
   ans++;   
  }
  
  cout << ans << endl;

  system("pause");
  return 0;
}
