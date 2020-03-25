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

 Node *FunctionName(Node *head){



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

head=obj.FunctionName(head);
obj.display(head);

}
