#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
     Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class Solution{
    public:

   Node *insert(Node *head,int val){
       Node *nn=new Node(val);
       if(!head){
           head=nn;
           return head;
       }
       Node *ptr=head;
       while(ptr->next){
           ptr=ptr->next;
       }
       ptr->next=nn;
       return head;
   }
 void display(Node *head){
     Node *ptr=head;
     while(ptr){
         cout << ptr->val << " ";
         ptr=ptr->next;
     }
 }


};
int main(){
Node *head=NULL;
Solution obj;
head=obj.insert(head,1);
head=obj.insert(head,2);
head=obj.insert(head,3);
head=obj.insert(head,4);
head=obj.insert(head,5);
obj.display(head);

}
