#include<iostream>
using namespace std;

/*
Linear-time algorithm(using a little modification in KMP) to determine whether a text T is a cyclic rotation of another string T'.
For e.g. : "arc" and "car" are cyclic rotations of each other
*/

bool isCyclicRotation(string,string);

int main()
{
  cout<<"Text: ";
  string s;
  cin>>s;
  cout<<"Pattern: ";
  string p;
  cin>>p;
  
  cout<<isCyclicRotation(s, p)<<endl;
  
 system("pause");
 return 0;
}

bool isCyclicRotation(string s,string p)
{
  int n = s.size();
  int m = p.size(); 
  if(m != n) return false;
  //Basically m = n;
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
  
  while(i < n){ // Here, "i < n" is used instead of "i <= (n-m)" as we want to find the largest prefix of "p" that matches largest suffix of "s".
          while(q < m && i+q < n && s[i+q]==p[q]) // here i+q < n is another condition added
           q++; 
          if(i+q == n) break; // this is the modification done in KMP 
          int shift = q-h[max(0,q-1)];
          i = i + max(shift,1);
          q = h[max(0,q-1)];
  }
  //KMP ends
  
  int w = n-q;
  int j = 0;
  while(j < w && s[j] == p[q+j])
   j++;
   
  if(j == w)
   return true;
  else
   return false;
  
}
          
