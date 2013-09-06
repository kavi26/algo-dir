#include<iostream>
using namespace std;

string a[10][4] = {{}, {}, {"a", "b", "c", ""}, {"d", "e", "f",""}, {"g", "h", "i",""}, {"j", "k", "l", ""}, {"m", "n", "o", ""},
                   {"p", "q", "r", "s"}, {"t", "u", "v", ""}, {"w", "x", "y", "z"}};

void recursive(string s, string num){
 if(num == ""){
  cout << s << endl;      
  return; 
 }     
 recursive(s+a[num[0]-48][0], num.substr(1));
 recursive(s+a[num[0]-48][1], num.substr(1));
 recursive(s+a[num[0]-48][2], num.substr(1));
 if(a[num[0]-48][3] != "")
 recursive(s+a[num[0]-48][3], num.substr(1));
}

int main()
{
  string num = "235";
  
  recursive("",num);
  
  
  system("pause");
  return 0;
}
