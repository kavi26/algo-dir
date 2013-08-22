#include<iostream>
#include<gmp.h>
using namespace std;

static int k = 0;



void tower(char, char, char, int);

int main()
{
    int n;
    cout<<"Enter Number of Disc in Tower of Hanoi: ";
    cin>>n;
    cout<<"Tower of hanoi using "<<n<<" discs"<<endl;

    tower('A','B','C', n);
    cout<<"NUMBER OF MOVES: "<<k<<endl;
    
    system("pause");
    return 0;
}

void tower(char A, char B, char C, int n)
{
   if(n==0)
     cout<<"Move can't be completed"<<endl;
   if(n==1)
     {
      cout<<"Move disc from "<<A<<" to "<<C<<endl;
      k++;
     }
   else
   {
      tower(A,C,B,n-1);
      tower(A,B,C,1);
      tower(B,A,C,n-1);
   }
}
