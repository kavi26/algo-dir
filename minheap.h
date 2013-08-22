#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

const int MAXN = 100;

//Heap is a complete binary tree

class minHeap{
    private:
      int Size; // Size of Heap
      int H[MAXN];
      
     public: 
      minHeap(int size = 0): Size(size){
      }
      
      
     bool isEmpty(){
      if(Size <= 0) return true;
      else return false;     
     }
      
     int findMin(){
      if(isEmpty()){
       cerr<<"Heap is Empty "<<endl;             
       return INT_MAX; 
      }
      else 
       return H[1]; // the minimum element is at index 1
     }
     
     int extractMin(){ // delete the min and returns it
       if(isEmpty()){
        cerr<<"Heap is Empty "<<endl; 
        return INT_MAX;
       }
       else{
        int m = H[1];
        H[1] = H[Size];
        H[Size] = H[1]; // Although this is not required ; it is a key part of Heap-Sort
        Size--;
        Heapify(1); // Heapify operation for size one less than what was before calling this function.
        return m;
      }
     }
     
     int Left(int i){ // returns index of left element
         return 2*i;
     }
     
     int Right(int i){
        return 2*i+1;    
     }
     
     int parent(int i){
       return (i/2);    
     }
     
     void Heapify(int a){ // Heapify from node a
        int i = a;
        while(i < Size){
         int l = Left(i);
         int r = Right(i);
         if(l <= Size && r <= Size){
              if(H[l] > H[r] && H[i] > H[r]){ // right child is minimum and smaller than parent
               swap(H[r], H[i]);
               i = r;
               continue;        
              }
              else if(H[l] < H[r] && H[i] > H[l]){ // left child is minimum and smaller than parent
               swap(H[l], H[i]);
               i = l;
               continue;
              }
              break; //No swap is done
         }
         else if(l <= Size && H[i] > H[l]){
              swap(H[l], H[i]);
              i = l;
              continue;
         } else if(r <= Size && H[i] > H[r]){
              swap(H[r], H[i]);
              i = r;
              continue;
         } else break;
        }   
     }
        
     void insert(int a){
      if(Size+1 >= MAXN){
        cerr<<"Buffer is full. Size of heap can't be extended."<<endl;        
      }     
      else{
        Size++;
        H[Size] = a;
        //Comparing element with parent and swapping until either we find the order of heap or we reach the root
        int i = Size;
        int p = parent(i);
        while(p >= 1 && H[p] > H[i]){
          swap(H[p], H[i]);
          i = p;
          p = parent(i);
        }
      }
     }
     
     void decrPrior(int i, int key){ // decrease the priority of node at index i to new priority "key" -- similar to insert
        H[i] = key;
        int j = i;
        int p = parent(j);
        while(p >= 1 && H[p] > H[j]){
          swap(H[p], H[j]);
          j = p;
          p = parent(j);
        }
     }
    
      void incrPrior(int i, int key){ // increase the priority of node at position i to new priority "key" -- similar to heapifying operation
         H[i] = key;
         Heapify(i);
      }
      
      void deleteElement(int i){ // delete an arbitrary element present in Heap
        swap(H[i],H[Size]);
        Size--;
        int p = parent(i);
        if(p >= 1 && H[p] < H[i]){
          Heapify(i);
          return;     
        }
        if(p >= 1 && H[p] > H[i]){
          int j = i;
          while(p >= 1 && H[p] > H[j]){
          swap(H[p], H[j]);
          j = p;
          p = parent(j);
          }
          return;     
        }
      }
      
      void printHeap(){
           for(int i = 1; i <=Size; i++) cout<<H[i]<<" ";
           cout<<endl;
      }
};
