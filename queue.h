#include<iostream>
using namespace std;

struct node{
       int data;
       node*next;
};
 
class queue{
             
       node*head;
       node*tail;
       int size;// Number of element in queue.
       
       public:
              
       queue()
       {  head = tail = NULL;
          size = 0;
       }
       
       ~queue()
       { clear();
         delete head;
         
       }
       
       void clear()
       {    
             if(size == 0)
          { 
            cout<<"Queue is empty."<<endl;
            return ;
          } 
            while(head->next != NULL)
            {  node*temp = head;
               head = head->next;
               cout<<"Destructor in Action.\n";
               delete temp;
            }
            head = tail = NULL;
            size = 0;
            
            print();
       }
       
       void enqueue(int x)
       {   
            node*temp = new node;
            temp->data = x;
            temp->next = NULL;
             if(size == 0)
           { 
             head = temp;
             tail = temp;
             size++;
            // print();
             
             return;
           }
            tail->next = temp;
            tail = temp;
            
            size++;
            //print();
       }
       
       int dequeue()
       {
          if(size == 0)
          { 
            cout<<"Queue is empty."<<endl;
            return -1;
          } 
          node*temp = head;
          int x = temp->data;
          
          if(head == tail)
          {  head = tail = NULL;
             delete temp;
             size--;
          
           //  print();
             return x;
          }
          
          
          head = head->next;
          delete temp;
          size--;
          
          //print();
          return x;
       }
       
       int length()
       {  return size;}
       
       int frontvalue()
       {
           if(size == 0)
          { 
            cout<<"Queue is empty."<<endl;
            return 0;
          } 
          
          return head->data;
       }
       
       void print()
       {     if(size == 0)
          { 
            cout<<"Queue is empty."<<endl;
            return;
          } 
            node*temp =head;
            while(temp->next != NULL)
            { cout<<temp->data<<" ";
              temp = temp->next;
            }
            cout<<temp->data<<endl;
       }
       
      bool isEmpty(){
       if(size == 0) return true;
       return false;     
      }
};
