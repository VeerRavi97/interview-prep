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

 Node *reversek(Node *head,int n,int k){
  if(!head||!head->next || k>n) return head;
  Node *current=head;
  Node *pre=NULL;
  Node *next=current->next;
  int pos=1;
  while(current && pos<=k){
    next=current->next;
    current->next=pre;
    pre=current;
    current=next;
    pos++;
  }
 if(next) head->next=reversek(next,n-k,k);
 return pre;
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

head=obj.reversek(head,n,3);
 obj.display(head);

}
