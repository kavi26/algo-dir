#include<iostream>
using namespace std;

typedef long long ll;
const ll inf = (int) 1e100;

void MergeSort(int*, int, int);
void Merge(int*, int , int, int);

int main()
{
  int a[7] = {3,2,1,8,7,5,11};
  int sum = 13;
  //1.sort a[] -- theta(n*lgn)
  MergeSort(a,0,6);
  
  //2.Select aux set b such that for each element z in b, z = sum - y, where y belongs to a -- theta(n)
  int b[7];
  for(int i = 0; i < 7; i++) b[i] = sum - a[i];
  
  //3. Sort b -- theta(n)
  MergeSort(b,0,6);
  
  //4. Remove Duplicate elements in a and similarly in b and merge them, lool for duplicates in merged array -- theta(n)
  int i = 0;
  int j = 0;
  bool ans = false;
  while(i < 7 && j < 7){
   if(a[i] < b[j]) i++;
   else if(a[i] > b[j]) j++;
   else {
        ans = true;
        cout <<"elements found:" <<" ";
        cout<<a[i]<<" "<<sum-a[i]<<endl;
        i++;
   }
  }
  
  //Overall Complexity: theta(n*lgn)
            
  if(!ans) cout<<"No elements found"<<endl;       
  
  system("pause");
  return 0;
}

void MergeSort(int*a,int p,int r){
     if(p < r){
      int q = (p+r)/2;     
      MergeSort(a,p,q);
      MergeSort(a,q+1,r);
      Merge(a,p,q,r);
     }
}

void Merge(int*a,int p,int q,int r){
 int n1 = q-p+1;
 int n2 = r-q;
 ll L[n1+1];
 ll R[n2+1];
 for(int i = 0; i<n1; i++) L[i] = a[p+i];
 for(int j = 0; j<n2; j++) R[j] = a[q+j+1];
 L[n1] = R[n2] = inf;

 int i = 0;
 int j = 0;
 
 for(int k = p; k <= r; k++){
   if(L[i] <= R[j]){
    a[k] = L[i];
    i++;
   }    
   else{
    a[k] = R[j];
    j++;
   }        
}

}
