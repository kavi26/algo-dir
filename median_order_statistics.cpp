#include<iostream>
using namespace std;

int random(int, int);
int Partition(int*, int, int);
int Randomized_partition(int*, int, int);

int Randomized_select(int*A, int p, int r, int i) // finding i'th smallest number
{
  if(p == r)
   return A[p];
   
  int q = Randomized_partition(A,p,r);
  int k = q - p + 1;
  /* // Test 
  cout<<"p:" << p <<" q or j: " << q << " r: " << r << " i: " << i << " k: " << k <<endl;
  for(int i = 0; i < 10; i++)
  cout << A[i] << " ";
  cout << endl;
  */
  if(i == k)
   return  A[q]; // k is rank of A[q]
  
  else if(i < k)
       return Randomized_select(A,p,q-1,i);
       else
       return Randomized_select(A,q+1,r,i-k);
}

int main()
{
  
  int A[10] = {2,1,5,0,9,4,8,11,3,19};
  
  cout << Randomized_select(A,0,9,11) << endl;

  
  system("pause");
  return 0;
}

/* Following code is used directly from quickSort implementation */

int Randomized_partition(int*A, int p, int r){
 int i = random(p, r); // returns a random number between p and r     
 swap(A[i], A[r]); // as the pivot element is last element while executing "partition" block
 return Partition(A,p,r);
}

int random(int low, int high){
 int range = high-low+1;
 int random_integer = low + int(range * (rand()/(RAND_MAX + 1.0)));   
 return random_integer;
}

int Partition(int*A, int p, int r){
int pivot = A[r];
int i = p;
int j = r;
// cout<<"A[r]: "<<A[r]<<endl; //Test
while(true){
 while(A[j] > pivot && j >= p) j-- ;
 while(A[i] < pivot && i <= r) i++ ;
 if(i < j) swap(A[i], A[j]);
 else return j;
}    

}

