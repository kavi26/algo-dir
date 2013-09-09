#include<iostream>
using namespace std;

unsigned long long counts[10000];
unsigned long long combinations(unsigned k, unsigned n) {
     memset(counts, 0, sizeof(counts));
    unsigned i;
    unsigned temp = n/k;
    for(i = 1; i <= k; ++i) {
        counts[i%k] += temp;
    }
    
    temp = temp*k + 1;
    while(temp <= n){
     counts[temp%k]++;
     temp++;
    } 
    
    // number of pairs where both are divisible by k
    unsigned long long combs = counts[0]*(counts[0]-1)/2;
    for(i = 1; i < (k+1)/2; ++i) {
        combs += counts[i]*counts[k-i];
    }
    if (k == 2*i) {
        combs += counts[i]*(counts[i] - 1)/2;
    }
    return combs;
}

int main()
{
  cout << combinations(9896,1000000000) << endl;

  system("pause");
  return 0;
}
