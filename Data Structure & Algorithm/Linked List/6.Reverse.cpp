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
           kth++;
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
 Node *reverse(Node *head){
  if(!head||!head->next) return head;
  Node *current=head;
  Node *pre=NULL;
  Node *next=current->next;
  while(current){
    next=current->next;
    current->next=pre;
    pre=current;
    current=next;
  }
//   Node *ptr=pre;
//   while(ptr){
//          cout << ptr->data << " ";
//          ptr=ptr->next;
//      }
//      cout << pre->data << "\n";
  return pre;
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
obj.display(head);

Node *reversed=obj.reverse(head);

obj.display(reversed);
}
