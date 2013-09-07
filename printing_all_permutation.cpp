#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//printing all permutations of a string --- O(n* n!)
// for detailed solution :- http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

void permuteString(char*a, int i, int n){ // i -- starting index , n -- ending index
     if(i == n){
      printf("%s\n", a);    
      return;
     }
     
     for(int j = i; j <= n; j++){
      swap(*(a+i),*(a+j));
      permuteString(a, i+1, n);
      swap(*(a+i), *(a+j)); //Backtracking to same node
     }
}

int main()
{
  char a[50]; // size of string
  scanf("%s", &a);
  permuteString(a, 0, strlen(a)-1);

  system("pause");
  return 0;
}
