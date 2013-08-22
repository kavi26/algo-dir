#include<iostream>
using namespace std;
int main() 
{ 
 int i, j, k, n ; 
 float a[100][100], x[100] ; 
 double s, p ;  
 cout<<"Enter the number of equations: ";
 cin>>n; 
 cout<<"Enter the co-efficients of the equations: "; 
 for(i = 0 ; i < n ; i++) 
 { 
  for(j = 0 ; j < n ; j++) 
  { 
   cout<<"a["<<i+1<<"]["<<j+1<<"] = "; 
   cin>>a[i][j]; 
  } 
  cout<<"b["<<i+1<<"] = "; 
  cin>>a[i][n];
   
 } 
 for(k = 0 ; k < n - 1 ; k++) 
 { 
  for(i = k + 1 ; i < n ; i++) 
  { 
   p = a[i][k] / a[k][k] ; 
   for(j = k ; j < n + 1 ; j++) 
    a[i][j] = a[i][j] - p * a[k][j] ; 
  } 
 } 
 x[n-1] = a[n-1][n] / a[n-1][n-1] ; 
 for(i = n - 2 ; i >= 0 ; i--) 
 { 
  s = 0 ; 
  for(j = i + 1 ; j < n ; j++) 
  { 
   s += (a[i][j] * x[j]) ; 
   x[i] = (a[i][n] - s) / a[i][i] ; 
  } 
 } 
 cout<<"The result is:"<<endl;
 for(i = 0 ; i < n ; i++) 
 cout<<"x["<<i+1<<"] = "<<x[i]<<endl;
 system("pause");
 return 0;
}
