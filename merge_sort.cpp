#include<iostream>
using namespace std;

typedef long long ll;
const ll inf = (int) 1e100;

void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main(){
 int a[10] = {5,3,8,6,1,4,-9,13,24,10};
 MergeSort(a,0,9);
 for(int i=0;i<10;i++) cout<<a[i]<<" ";
 cout<<endl;
 
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
