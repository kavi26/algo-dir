#include "minheap.h"

int main()
{
  minHeap Hp;
  Hp.insert(3);
  Hp.printHeap();
  Hp.insert(2);
  Hp.printHeap();
  Hp.insert(1);
  Hp.printHeap();
  Hp.insert(5);
  Hp.printHeap();
  Hp.insert(9);
  Hp.printHeap();
  
  cout<<Hp.extractMin()<<endl;
  Hp.printHeap();
  
  
  system("pause");
  return 0;
}
