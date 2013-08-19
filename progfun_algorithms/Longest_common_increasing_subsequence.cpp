// Tutorial:- http://blog.codechef.com/2009/05/19/211/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cmath>
#include<fstream>
#include<cstring>
using namespace std;

#define in(a,low,high) for(int i=low;i<high;i++)cin>>a[i]
#define out(a,low,high) for(int i = low;i<high;i++)cout<<a[i]<<" "

int gcd(int a,int b) // Euclid's Algorithm
{ int t;
  while(b != 0){t = b;
                b = a%b;//b works as remainder
                a = t;}
  return a;
}

int lcm(int a,int b)
{
  return (a*b)/gcd(a,b);
}

int main()
{ int seq1[5001]={0};
  int seq2[5001]={0};
  int n,m;
  cin>>n; 
  for(int i=1;i<=n;i++) cin>>seq1[i];  // Put seq1 in first column of imaginary 2-d array
  cin>>m;
  for(int i=1;i<=m;i++) cin>>seq2[i]; // Put seq2 in first row of imaginary 2-d array
  
  int aux[m+1];                      // aux[i] represents maximum length of LCIS ending at seq2[i].
  for(int i=0;i<=m;i++) aux[i]=0;
  
  int pred[m+1];                       // pred[i] stores the index of previous element in seq2(m) which make LCIS maximum at seq2[i].
  for(int i=0;i<=m;i++) pred[i]=0;
  
  int maxv = 0;
  
  int temp=0; // Stores the index of previous element in seq2(m) which make LCIS maximum at seq2[i].
  
  for(int i=1;i<=n;i++){
          maxv = 0; 
          for(int j=1;j<=m;j++){
                  if(seq2[j]<seq1[i]){
                                     if(aux[j]>maxv){
                                                    maxv = aux[j];
                                                    temp = j;
                                     }
                  } 
                  if(seq1[i]!=seq2[j]) continue;
                  else{
                       aux[j]=maxv+1;
                       pred[j]=temp;
                       break;
                  }
          }
  }
//  for(int i=0;i<=m;i++) {for(int j=0;j<=n;j++) cout<<a[i][j]<<" "; cout<<endl;}
  maxv = 0;
  for(int i=1;i<=m;i++){
          if(aux[i]>maxv){
                          maxv = aux[i];
                          temp = i;
          }
  }
  
  cout<<"Length of LCIS: "<<maxv<<endl;
  
  cout<<"LCIS: ";
  int x[maxv];
  int l = maxv-1;
  while(temp!=0){
                 x[l]=seq2[temp]; l--;
                 temp = pred[temp];
  }
  
  out(x,0,maxv);
   
                       
                  
   system("pause");
  return 0;
}
