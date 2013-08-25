#include<iostream>
#include<vector>
#include<map>
using namespace std;

//finding the range of continuous subsequences which sum to 0

int main()
{
  int n;
  cin>>n;
  
  int a[n];
  for(int i = 0; i < n; i++)
   cin >> a[i];
   
  int b[n+1];
  b[0] = 0;
  for(int i = 1; i < n+1; i++) b[i] = b[i-1] + a[i-1]; // b[i] stores sum
  
  //Now look for repeated values in b[], the interval between these values sum to 0, as then only value the two b[] values remain same(nothing is added).
  multimap<int, int> m;
  for(int i = 0; i < n+1; i++){
    // cout<<b[i]<<" "<<i<<endl;
     m.insert(pair<int, int>(b[i], i)); // initialising a pair and inserting it into multimap       
  }
  vector<int> ind[n];
  
  multimap<int, int>::iterator it;
  int l = 0;
  for(it = m.begin(); it != m.end(); ++it){
   int key = it->first;
   //cout<<key<<endl;
   pair<multimap<int, int>::iterator, multimap<int, int>::iterator> p = m.equal_range(key);
   multimap<int, int>::iterator temp = p.first;
   if(++temp == p.second) continue; // check if p.second is just next to p.first or not.
   multimap<int, int>::iterator ite;
   
   for(ite = p.first; ite != p.second; ite++)
    ind[l].push_back(ite->second);
    
   it = ite;
   l++;
  }
  
  for(int i = 0; i < l; i++){
   int sz = ind[i].size();
   for(int j = 0; j < sz; j++){
    for(int s = j+1; s < sz; s++){
    cout<< ind[i][j] << " " << ind[i][s]-1<<endl; 
    }        
   }
  }
  
  system("pause");
  return 0;
}
