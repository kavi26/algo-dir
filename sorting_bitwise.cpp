#include<iostream>
using namespace std;

/*
Given an array having 16000 unique integers, each lying within the range 1<x<20000, Sort it without loading more than 1000 numbers at a time in memory.
*/

int main()
{
  int data[20000] = {97,6,64,37,36};	// initially given unique data
  int arr[625] = {64,48,1,2}; // bit vector array arr[data[i] / 32] = power(2, data[i] % 32); on collision take XOR. 
  int index = 0;	// index to store back all data

  for(int i=0; i<=625; i++)
	for(int j=0; j<32; j++)
		if(arr[i] & (1 << j))
			data[index++] = i*32 + j;
			
  for(int i = 0; i < 10; i++)
   cout << data[i] <<" ";
   cout<<endl;
  
  system("pause");
  return 0;
}
