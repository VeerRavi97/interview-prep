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

 Node *deletion(Node *head,int nth){
   if(!head || nth==0){
       Node *temp=NULL;
       if(head)
        temp=head->next;
       delete(head);
       return temp;
   }
   Node *ptr=head;
   Node *pre=NULL;
   int k=0;
   while(ptr && k<nth){  
pre=ptr;
ptr=ptr->next;
k++;
   }
   pre->next=ptr->next;
   delete(ptr);
   return head;
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
head=obj.deletion(head,0);
obj.display(head);
obj.deletion(head,2);
obj.display(head);

}
