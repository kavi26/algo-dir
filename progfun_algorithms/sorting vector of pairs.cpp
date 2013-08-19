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

#define forn(i, n) for(int i=0;i < (int)(n); i++)
#define mp make_pair

typedef long long ll;
typedef long double dbl;

const ll inf = (int) 1e100;



inline bool less1(pair<int,int> i, pair<int,int> j ) { return  (i.second<j.second) ;}



int main()
{ 
  int n;
  cin>>n;
  
  pair<int,int> pii[n];
  
  forn(i,n){
            cin>>pii[i].first>>pii[i].second;
  }
  
  sort(pii,pii+n,less1);
  
  forn(i,n){
            cout<<pii[i].first<<" "<<pii[i].second<<endl;
  }

  system("pause");
  return 0;
}
