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

int coin_changing(int*,int,int);
int change(int*,int,int*,int );

int main()
{
  int n;
  cin>>n;
  int m;
  cin>>m;
  int coins[m];
  in(coins,0,m);
  int x = coin_changing(coins,n,m);
  
  cout<<x<<endl;
  
  system("pause");
  return 0;
}


int coin_changing(int*coins,int n,int m){
    int r[n+1];
    r[0]=0;
    for(int i=1;i<n+1;i++) r[i]=-1;
    
    return change(coins,n,r,m);
}

int change(int*coins,int n,int*r,int m){
    if(n<0) return -1;
    if(r[n]!=-1) return r[n];
    
    int q=-1;
    for(int i=0;i<m;i++){
            q = max(q,change(coins,n-coins[i],r,m));
           // cout<<"q = "<<q<<endl;
    }
    if(q>=0){
            r[n]=q++;
        
            }
    return q;
}
