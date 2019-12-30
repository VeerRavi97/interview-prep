#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
     Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Solution{
    public:

   Node *insert(Node *head,int data,int nth){
       Node *nn=new Node(data);
       if(!head || nth==0){
           head=nn;
           return head;
       }
       int kth=0;
       Node *current=head;
       Node *pre=NULL;
       while(current&& kth<nth){
           pre=current;
           current=current->next;
       }
       pre->next=nn;
       nn->next=current;
       return head;
   }
 void display(Node *head){
     Node *ptr=head;
     while(ptr){
         cout << ptr->data << " ";
         ptr=ptr->next;
     }
     cout << "\n";
      }

 Node* nthfromlast(Node *head,int n){
  Node *slow=head;
  Node *fast=head;
  int k=1;
  while(k<n)
  {
      k++;
  fast=fast->next;
  }
  while(fast && fast->next){
      slow=slow->next;
      fast=fast->next;
  }
  return slow;

 }


};
int main(){
Node *head=NULL;
Solution obj;
head=obj.insert(head,1,0);
head=obj.insert(head,2,1);
head=obj.insert(head,3,2);
head=obj.insert(head,4,3);
head=obj.insert(head,5,4);
head=obj.insert(head,6,5);
obj.display(head);
Node *last=obj.nthfromlast(head,2);
cout << last->data << "\n";

}
