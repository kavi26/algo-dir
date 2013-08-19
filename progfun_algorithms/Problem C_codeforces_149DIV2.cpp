#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<fstream>
#include<cstring>
using namespace std;

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

set<pair<int,int> > s;     // Set contains all set of coordinates on chess-board (a,b) which are allowed for king.
map<pair<int,int>,int> m;//HASHING:- "map" maps each element of set to an int giving its shortest dist from (x0,y0) and checking if visited or not(count).
queue<pair<int,int> > q;  // pushing neighbouring co-ordinates into queue for BFS.

int main()
{ 
  long long x0,y0,x1,y1;
  cin>>x0>>y0>>x1>>y1;
  long long r,a,b;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
          cin>>r>>a>>b;
          for(int j=a;j<=b;j++){
                  s.insert(make_pair(r,j));
          }
  }
  
  q.push(make_pair(x0,y0));
  
  m[make_pair(x0,y0)] = 0;
  
  while(!q.empty()){
                    int x = q.front().first, y = q.front().second, d = m[make_pair(x,y)];
                    q.pop();
                    for(int i=-1;i<=1;i++){
                            for(int j=-1;j<=1;j++){
                                    pair<int,int> temp = make_pair(x+i,y+j);
                                    if(m.count(temp) || !s.count(temp)) continue; //neighbour "temp" is either visited or not allowed (not present in set).
                                    q.push(temp);
                                    m[temp] = d+1;
                                    if(temp.first==x1 && temp.second==y1){
                                                               cout<<d+1<<endl;
                                                               system("pause");
                                                               return 0;
                                    }
                            }
                    }
  }
  
  cout<<"-1"<<endl;
                                    
  system("pause");
  return 0;
}
