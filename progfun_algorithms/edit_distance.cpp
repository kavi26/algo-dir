#include<iostream>
#include<cstring>
using namespace std;

// Edit-distance problem --
// For more info:- http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
/*
Problem: Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost. 
Find minimum number of edits (operations) required to convert one string into another(called edit distance).
*/

#define EDIT_COST 1

int edit_distance(string X, string Y){ // X is vertical and Y is horizontal in 2-D array T
 int m = X.length();
 int n = Y.length();
 
 int T[100][100];
 
 memset(T, -1, sizeof(T));
 
 for(int i = 0; i < m+1; i++)
  T[i][0] = i; // Number of edits to convert string of length i into empty string
  
 for(int i = 0; i < n+1; i++)
  T[0][i] = i; // // Number of edits to convert string of length 0 into string of length i
 
 for(int i = 1; i < m+1; i++)
  for(int j = 1; j < n+1; j++){ // Evaluating T[i][j] using T[i][j-1](from left) , T[i-1][j](from top) and T[i-1][j-1](from diagonal) cells
   int fromLeft, fromTop, fromDiagonal;
   fromLeft = T[i][j-1] + EDIT_COST; // forming T[i][j] from T[i][j-1] by inserting j'th character in Y
   fromTop = T[i-1][j] + EDIT_COST; 
   fromDiagonal = T[i-1][j-1] + (X[i-1] != Y[j-1]); // if X[i-1] != Y[j-1] replace Y[j-1] by X[i-1] else they matches, hence do nothing
   
   T[i][j] = min(fromLeft, min(fromTop, fromDiagonal));       
  }
 return T[m][n];
}

int main()
{
 string s1, s2;
 cin >> s1 >> s2;
 int sol = edit_distance(s1, s2);
 cout << "Minimum number of edits: " << sol << endl;
  system("pause");
  return 0;
}
