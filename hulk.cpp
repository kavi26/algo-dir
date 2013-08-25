#include<iostream>
#include<cstdio>
using namespace std;

//prints the number of lexicgraphically smaller or equal strings of same size as a given string

const int MAX = 102, MOD = 1009;
int dp[MAX][27],len, sstrings[MAX];
char str[27];

int solve(int i, int prev){
 if(i == len) 
  return dp[i][prev] = 1;
 
 if(dp[i][prev] == -1){
  dp[i][prev] = 0;
  for(int c = 'a'; c < (int)str[i]; c++)
   if(prev != c - 'a')
    dp[i][prev] = (dp[i][prev] + sstrings[len-i-1]) % MOD;
  
  if(str[i] - 'a' != prev )
   dp[i][prev] = (dp[i][prev] + solve(i+1, str[i] - 'a')) % MOD;               
                
 }   
    
 return dp[i][prev];
}

int main(){
    scanf("%s", str);
	len = strlen(str);
	sstrings[0] = 1;
	for (int i = 1; i <= len; i++)	
	 sstrings[i] = (sstrings[i-1] * 25) % MOD;
	memset(dp, -1, sizeof(dp));
	cout<<solve(0,26)<<endl;
    system("pause");
	return 0;
 }   
    
    
    

