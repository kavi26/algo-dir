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

/*This function calculates (a*b)%c for very large a & b */
long long mulmod(long long a,long long b,long long c){
     long long x=0,y=a%c;
     while(b>0){
                if(b%2==1){
                           x = (x+y)%c;
                }
                y = (y*2)%c;
                b /= 2;
     }
     return x%c;
} 

/*This function calculates (a^b)%c for very large a and b */
long long modulo(int a,int b,int c){
    long long x=1,y=a;
    while(b>0){
               if(b%2==1){// b is odd
                  x = (x*y)%c; // Use mulmod(x,y,c) if y is out of 64_bit
               }
               y = (y*y)%c; // Use mulmod(y,y,c) if y is out of 64_bit
               b /= 2;
    }
    return x%c;
}

/* Miller - Rabin Primality Test, Iteration signifies the accuracy of the test*/
bool MRP(long long n,int iteration){
     if(n<2) return false;
     if(n!=2 && n%2==0) return false;
     
     long long s = n-1;
     while(s%2==0) s/=2; // Bring out the s in n-1=(2^d)*s and remember s is odd
     
     for(int i=0;i<iteration;i++){
             long long a = rand()%(n-1)+1;//  2<=a<=n-2
             long long x = modulo(a,s,n);
             if(x==1 || x==n-1) continue; // Probably Prime
             bool m = 0;
             for(int r=1;r<=s-1;r++){
                     x = (x*x)%n; // mulmod(x,x,c) can be used
                     if(x==1) return false;// x is definitely composite, n fails MRP test.
                     if(x==n-1){ m=1; break; }// Probably prime.
             }
             if(m==1) continue;
             return false; // if m remains equal to 0
     }
     
     return true; // Almost surely prime.
}
             
int main()
{ long long n;
  for(int i=0;i<100;i++){
  cin>>n;
  if(MRP(n,40)) cout<<n<<" is prime"<<endl;
  else cout<<n<<" isn't prime"<<endl;
}
  system("pause");
  return 0;
}
