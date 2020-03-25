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

 Node *rotate(Node *head,int n,int k){
  if(!head || !head->next) return head;
  Node *last=head;
  while(last->next) last=last->next;
  last->next=head;
  k=k%n;
  int d=n-k;
  int nth=1;
  Node *current=head;
  Node *pre=NULL;
  while(nth<=d && current){
      nth++;
      pre=current;
      current=current->next;
  }
  pre->next=NULL;
  head=current;
//   cout << k << " " << n << " " << last->val << " " << pre->val << "\n";
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
int k;
cin >> k;
head=obj.rotate(head,n,k);
obj.display(head);

}
