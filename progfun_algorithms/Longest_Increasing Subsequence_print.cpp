#include<iostream>
using namespace std;

int Binarysearch(int*a,int c,int d,int key)
{   if(d<=c)
    return c;
    if(a[(c+d)/2]<key)
    { c = (c+d)/2 + 1;
      return Binarysearch(a,c,d,key);
    }
    else{ d = d-(c+d)/2;
          return Binarysearch(a,c,d,key);
    }
}

int main()
{   cout<<"Size: ";
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int end[n];// Storing the end elements of the sequences formed till now.
    int num[n];// num[i] store the index of end[i] in array a[].
    int pred[n];// Assuming that LIS ends at x[i], pred[i] stores the previous element of that LIS ending at x[i].
    
    end[0] = a[0];
    num[0] = 0;
    pred[0] = -1;
    int len = 1;
    
    for(int i=1;i<n;i++)
    {
      if(a[i]<end[0])
      { end[0] = a[i];
        num[0] = i;
        pred[i] = -1;
        continue;
      }
      else if(a[i]>=end[len-1])
           { end[len] = a[i];
             num[len] = i;
             pred[i] = num[len-1]; // As the new list will begin after the end element of just previous list.So pred[i] = index of previous end element.
             len++;
             
              continue;
           }
           else{
                 // Binary searh in end[] for smallest element greater than a[i]
                 int c = 0;
                 int d = len-1;
                 int j =  Binarysearch(end,c,d,a[i]);
                 end[j] = a[i];
                 num[j] = i;
                 pred[i] = num[j-1];
                
                }
      
      }
      
      cout<<"Size of Longest Sequence:- "<<len<<endl;
      cout<<"Longest increasing Sequence:- ";
      int i = num[len-1];
      int temp[len];
      int k=len-1;
      while(i!=-1){
                         temp[k] = a[i];
                         i = pred[i];
                         k--;
      }
      
      for(int j=0;j<len;j++) cout<<temp[j]<<" ";
      
      cout<<endl;
      
      
      system("pause");
      return 0;
}
      
              
    
