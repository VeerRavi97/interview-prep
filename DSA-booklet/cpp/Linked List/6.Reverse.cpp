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
  head=pre;
  return head;
 }

 Node *reverse_Range(Node *head,int m,int n){
   if(!head || !head->next || m==n) return head;
   Node *prev=nullptr;
   Node *next=nullptr;
   Node *current=head;
   Node *revhead=head;
   int k=1;
   cout << "head " << "\n";
   while(k<n){
     if(k<m) 
     {prev=current;
     current=current->next;
     }
     revhead=revhead->next;
     k++;
   }
   next=revhead->next;
   revhead->next=nullptr;
//    cout << prev->val << " " << current->val << " " << revhead->val << " " << next->val << "\n";
   revhead=reverse(current);
//    display(revhead);
if(prev)
   prev->next=revhead;
   else
   {
       head=revhead;
   }
   
   current->next=next;
  return head;
 } 


};
int main(){
Node *head=NULL;
Solution obj;
int n;
cin >> n;
for(int i=0;i<n;i++){
int in;
cin >> in;
head=obj.insert(head,in);
}

head=obj.reverse_Range(head,2,5);
 obj.display(head);

}
