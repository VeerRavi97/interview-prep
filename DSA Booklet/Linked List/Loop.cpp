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
  bool hasCycle(Node *head,Node **slowref,Node **fastref) {
        
    Node *slow=*slowref;
    Node *fast=*fastref;
        while(fast && fast->next){
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                *slowref=slow;
                *fastref=fast;
                return true;
            }
            
            
        }
        return false;
        
    }
    Node *StartingNode(Node *head) {
        
        
          Node *slow=head;
          Node *fast=head;
          Node *pre=NULL;
        if(hasCycle(head,&slow,&fast)){
             
            slow=head;
            while(slow!=fast){
                pre=fast;
                slow=slow->next;
                fast=fast->next;
        
            }
         // remove loop
         pre->next=NULL;  
           
         return slow;
            
            
            
            
        }
    
            return NULL;
        
        
        
        
    }

 int LoopLength(Node *head){
  Node *fast=head;
  Node *slow=head;
  if(hasCycle(head,&slow,&fast)){
   Node *slow=slow->next;
   int cnt=1;
   while(slow!=fast){
       cnt++;
       slow=slow->next;
   }
   return cnt;

  }
return -1;

 }   

  


};
int main(){
Node *head=NULL;
Solution obj;


}
