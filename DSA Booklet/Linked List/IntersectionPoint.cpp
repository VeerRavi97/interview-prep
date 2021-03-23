#include<bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
      int data;
    SinglyLinkedListNode* next;
  };
 

int length(SinglyLinkedListNode *head){
        
      
        int count=0;
        while(head){
            
            count++;
            head=head->next;
        }
        
     return count;   
    }
    
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
 if(!head1 || !head2) return NULL;
        
        int m=length(head1);
        int n=length(head2);
        int d=abs(m-n);
        if(m>n){
            for(int i=0;i<d;i++)
                head1=head1->next;
        }
        else{
             for(int i=0;i<d;i++)
                head2=head2->next;
        }
        while(head1 && head2){
            
            if(head1==head2) return head1->data;
            head1=head1->next;
            head2=head2->next;
        }
        
        return 0;

}