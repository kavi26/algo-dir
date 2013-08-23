#include<iostream>
using namespace std;

const int MAXN = 100;

void printOptimalSolution(int [MAXN][MAXN], int, int);

int main()
{
  int n; //number of matrices
  cin>>n;
  pair <int, int> A[n]; // A[i].first represent rows and A[i].second represent colums
  
  for(int i = 0; i < n; i++){
   cin >> A[i].first >> A[i].second;        
  }
  
  int m[MAXN][MAXN]; // m[i][j] stores the cost of multiplying matrices in range [i..j], both inclusive
  int s[MAXN][MAXN]; // s[i][j] stores the partition k, such that s[i..k]*s[k+1..j] have optimal solution inside m[i..j] 
  
  for(int i = 0; i < MAXN; i++) m[i][i] = 0; //single matrix, no multiplication and hence no cost
  
  for(int i = 0; i < MAXN; i++)
   for(int j = 0; j < MAXN; j++)    
    if(i != j) m[i][j] = INT_MAX;  
  
  //L is substructure chain's length
  for(int L = 1; L <= n; L++){
   for(int i = 0; i < n-L; i++){
    int j = i+L; 
    int k;
    int q;
    for(k = i; k < j; k++){
     q = m[i][k] + m[k+1][j] + A[i].first*A[k].second*A[j].second;
     if(q < m[i][j]){
      m[i][j] = q;
      s[i][j] = k;     
     }
    // cout<<i<<" "<<j<<" "<<k<<" "<<m[i][j]<<endl;
    }       
           
   }        
          
  }
       
   
   cout<<"Optimal Cost: "<<m[0][n-1]<<endl;
   cout<<"Optimal Parenthesization: "<<endl;
   printOptimalSolution(s,0,n-1);
          
   
  system("pause");
  return 0;
}

void printOptimalSolution(int s[MAXN][MAXN], int i, int j){
 if(i == j){
  cout<<"A["<<i<<"]";
  return;     
 }     
 else{
  cout<<"(";
  printOptimalSolution(s,i,s[i][j]);
  printOptimalSolution(s,s[i][j]+1,j);     
  cout<<")";    
 }
}
