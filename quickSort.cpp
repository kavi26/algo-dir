#include<iostream>
using namespace std;

int random(int, int);
int Partition(int*, int, int);
int Randomized_partition(int*, int, int);
void Randomized_quickSort(int*, int, int);

int main()
{
  int A[10] = {2,1,5,0,9,4,8,11,3,19};
  int B[5] = {16, 2, 77, 40, 12071};
  
  Randomized_quickSort(A, 0, 9);
  Randomized_quickSort(B,0,4);
  
  for(int i = 0; i < 10; i++)
   cout << A[i] << " ";
  
   cout << endl;
  
  for(int i = 0; i < 5; i++)
   cout << B[i] << " ";
   
   cout << endl;
  
  system("pause");
  return 0;
}

void Randomized_quickSort(int*A, int p, int r){
 if(p < r){
  int q = Randomized_partition(A,p,r); // This returns an index j, such that all elements before index j are less than all elements after j
  Randomized_quickSort(A,p,q);
  Randomized_quickSort(A,q+1,r);     
 }     
}

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

while(true){
 while(A[j] >= pivot && j >= p) j-- ;
 while(A[i] < pivot && i <= r) i++ ;
 if(i < j) swap(A[i], A[j]);
 else return j;
}    

}

