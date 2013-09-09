#include<iostream>
#include<climits>
using namespace std;

/*
Finding greatest sum sub-array in a given array.
For example, in the array {1, -2, 3, 10, -4, 7, 2, -5}, its sub-array {3, 10, -4, 7, 2} has the maximum sum 18.


Solution: O(n) time complexity. 
Use an accumulated sum from beginning, if it's positive keep it(becuase then on leaving it, we are basically reducing sum). If it is 0 or negative,
set accumulated sum to current element, because we don't want to reduce sum. Also, meanwhile keep a greatestSum variable to keep track whether the 
accumulated sum has exceeded the current maximum value or not, if so, greatestSum = accumulatedSum and continue till end of array.

*/

int greatestSumSubArray(int*a, int n){
 int greatestSum = INT_MIN;
 int accumSum = 0;
 for(int i = 0; i < n; i++){
    if(accumSum <= 0)
     accumSum = a[i];
    else
     accumSum += a[i];
     
    if(accumSum > greatestSum)
     greatestSum = accumSum;     
 }    
    
  return greatestSum;
    
}


int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
   cin >> a[i];
   
  int maxSum = greatestSumSubArray(a,n);
  cout << "Greatest sum of this subarray: " << maxSum << endl;

  system("pause");
  return 0;
}
