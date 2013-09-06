#include<iostream>
#include<cstring>
using namespace std;

//Longest common substring -- looking for longest common suffixes
// For good explanation -- http://www.youtube.com/watch?v=RUckZMzqUcw

/*
The complexity of solution is O(n^2), however it can be done in O(n) using suffix trees(which is pretty complex to code from competition point of view).
*/

int LCSuff[100][100];

int LCSubStr(string X, string Y){
 int m = X.length();
 int n = Y.length();
 
 memset(LCSuff, 0, sizeof(LCSuff));
 int longest = 0;
 string LCSubstring = "";
 // Assume X to be on vertical axis (from 1 to m), and Y on horizontal axis (from 1 to n)
 for(int i = 1; i <= m; i++){
  for(int j = 1; j <= n; j++){
   if(X[i-1] == Y[j-1]){
    LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
    if(LCSuff[i][j] > longest){
     longest = LCSuff[i][j];   
     LCSubstring =   X.substr(i-longest,longest);           
    }
   }
  }        
 }
 
 cout << "Longest common substring: " << LCSubstring << endl;
 return longest;
}


int main()
{
   string s1, s2;
   cin >> s1 >> s2;
   
   cout << "length: " << LCSubStr(s1,s2) << endl;

  system("pause");
  return 0;
}
