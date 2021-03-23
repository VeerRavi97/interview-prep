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

   Node *middle(Node *head){
   Node *slow=head;
   Node *fast=slow;
   Node *pre=NULL;
   while(fast&&fast->next){
       pre=slow;
       slow=slow->next;
       fast=fast->next->next;
   }
   if(!fast)slow=pre;
   return slow;

   }
 void display(Node *head){
     Node *ptr=head;
     while(ptr){
         cout << ptr->data << " ";
         ptr=ptr->next;
     }
     cout << "\n";
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
Node *mid=obj.middle(head);
cout << mid->data << "\n";

}
