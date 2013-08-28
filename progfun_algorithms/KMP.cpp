#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<cstring>
using namespace std;

#define in(a,low,high) for(int i=0;i<high;i++)cin>>a[i]
#define out(a,low,high) for(int i = low;i<high;i++)cout<<a[i]<<" "

static int ans = 0;
void KMP(string,string);

int main()
{
  cout<<"Text: ";
  string s;
  cin>>s;
  cout<<"Pattern: ";
  string p;
  cin>>p;
  
  ans = 0;
  KMP(s,p);
  cout<<ans<<endl;
  
 system("pause");
 return 0;
}

void KMP(string s,string p)
{
  int n = s.size();
  int m = p.size(); 
  if(m>n)return;
  if(m==n) 
  { if(s==p){
             ans++;
            }
   return;
  }
  // Pre-computation of h[] starts
  int h[m];
  h[0]=0;
  int k = 0;
  for(int q=1;q<m;q++){
          while(k>0 && p[k]!=p[q] )
            k = h[k];
            
          if(p[k]==p[q])
           k = k+1;
           
           h[q]=k;
          // cout<<h[q]<<endl;
  }                 
  // Pre-Computation of h[] ends
  
  //KMP starts
  
  int q = 0;
  int i = 0;
  
  while(i<=(n-m)){
          while(s[i+q]==p[q] && q<m)
           q++; 
          if(q==m) 
          {
             cout<<"index of "<<ans+1<<" match: "<< i << endl; 
             ans++;
          }
          int shift = q-h[max(0,q-1)];
          i = i + max(shift,1);
          q = h[max(0,q-1)];
  }
  //KMP ends
  
}
          
