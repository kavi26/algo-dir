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

static string ans="";

int LCS(string, string,int,int);
int lcs(string, string,int,int,int [100][100]);
string backtrack(string , string ,int ,int ,int [100][100]);
int dp(string x, string y,int a,int b);

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  
  ans="";
 int x = LCS(s1,s2,s1.size()-1,s2.size()-1);
  
  cout<<x<<endl;
  cout<<ans<<endl;
  cout<<"bottom-up dp: "<<dp(s1,s2,s1.size()-1,s2.size()-1)<<endl;

  system("pause");
  return 0;
}

int LCS(string x, string y,int a,int b){
    int C[100][100]={0}; // Changing Quantity
    int z = lcs(x,y,a,b,C);
    for(int i=0;i<=a;i++) {for(int j=0;j<=b;j++)cout<<C[i][j]<<" ";cout<<endl;}
    ans = backtrack(x,y,a,b,C);
    return z;
    
}

int lcs(string x, string y,int a,int b,int C[100][100]){
    if(a==-1 || b==-1) return 0;
    if(C[a][b]!=0) return C[a][b];
    
    if(x[a]==y[b]) { C[a][b] = lcs(x,y,a-1,b-1,C)+1;
                     return C[a][b];
    }
    else {
         C[a][b]=max(lcs(x,y,a,b-1,C),lcs(x,y,a-1,b,C)) ;
         return C[a][b];
         }
}   


string backtrack(string x, string y,int a,int b,int C[100][100]){ /* Similarly reading out all LCS can be done*/
       if(a==-1||b==-1) return "";
       if(x[a]==y[b]){cout<<a<<" = "<<b<<endl; return backtrack(x,y,a-1,b-1,C)+ x[a];}
       else if((b>0 ? C[a][b-1] : 0)>(a>0 ? C[a-1][b] : 0)){cout<<"Case I: Moving to i = "<<a<<" and j = "<<b-1<<endl; return backtrack(x,y,a,b-1,C);}
       else {cout<<"Case II: Moving to i = "<<a-1<<" and j = "<<b<<endl; return backtrack(x,y,a-1,b,C);}
}

// Bottom up dp 
/*
int dp(string x,string y,int a,int b){    // Its space complexity can be decreased from O(mn) to O(min(m,n)) using Hirschberg Algorithm.
    int C[100][100]={0};
    for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                    if(x[i]==y[j]){
                                   C[i+1][j+1]=C[i][j]+1;
                    }
                    else {
                         C[i+1][j+1] = max(C[i][j+1],C[i+1][j]);
                    }
            }
    }
    for(int i=0;i<=a+1;i++){ for(int j=0;j<=b+1;j++)cout<<C[i][j]<<" "; cout<<endl;}
    return C[a+1][b+1];
}   
*/

/*Bottom up dp determining length(only) of LCS with space 2*min(m,n)*/
 int dp(string x, string y,int a,int b){ // a>b
    int C[2][b+2];
    for(int i=0;i<2;i++) for(int j=0;j<b+2;j++) C[i][j]=0;
    int k=1;       
    
    for(int i=1;i<=a+1;i++){ // Move row-wise current row ->previous row->current row......so on. Don't move column wise as it would give errors!!
            if(k>1) k=0;
            for(int j=1;j<=b+1;j++){
                    
                    if(x[i-1]==y[j-1]){
                                       if(k==0) C[k][j]=C[k+1][j-1]+1;
                                       if(k==1) C[k][j]=C[k-1][j-1]+1;
                    }
                    else{
                         if(k==0) C[k][j]=max(C[k+1][j],C[k][j-1]);
                         if(k==1) C[k][j]=max(C[k-1][j],C[k][j-1]);
                    }
            }
            k++;
    }
    k--;
    return C[k][b+1];
}
                                 
   
