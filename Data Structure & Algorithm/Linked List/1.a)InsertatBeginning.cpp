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

   Node *insert(Node *head,int data){
       Node *nn=new Node(data);
       nn->next=head;
       head=nn;
       return head;
   }
 void display(Node *head){
     Node *ptr=head;
     while(ptr){
         cout << ptr->data << " ";
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
