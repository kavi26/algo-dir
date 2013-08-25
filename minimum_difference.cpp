#include<iostream>
#include<cmath>
using namespace std;

/*Finding a number in the array having least difference with the given number q, the query  --- complexity is O(log n)*/

int BinarySearch(int*A, int a, int b, int q){
 if(b <= a) {
      if(abs(A[b]-q) > abs(A[a]-q))     
      return a;
      else
      return b;
 }
 int mid = (a+b)/2;   
 if(A[mid] >= q) return BinarySearch(A,a,mid,q);
 else {
      if(abs(A[mid]-q) > abs(A[mid+1]-q))
      return BinarySearch(A,mid+1,b,q);
      else
      return mid;   
 }
}

int main()
{
  int n;
  cin >> n;
  
  int A[n]; // A[n] is sorted 
  for(int i = 0; i < n; i++)
   cin >> A[i];
  
  int q; // query for which we have to answer the element in A[n] with least difference from q.
  cin >> q;
  
  int ans = BinarySearch(A,0,n-1,q);
  cout << "index: " << ans+1 << endl;
  cout<< "element: "<< A[ans] << endl;
  
  
  system("pause");
  return 0;
}
