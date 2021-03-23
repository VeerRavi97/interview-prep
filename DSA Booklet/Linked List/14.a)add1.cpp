#include<bits/stdc++.h>
using namespace std;
int carry=0;
class Node{
	public:
	int val;
	Node *next;	
	Node(int val){
		this->val=val;
		this->next=NULL;
	}
};
// hello
class Solution{
	
	public:
	Node* insert(Node *head,int val){
		Node *nn=new Node(val);
		if(!head) return nn;
		Node *ptr=head;
		while(ptr->next) ptr=ptr->next;
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


	Node *addLists(Node *head1, Node *head2,int n,int m){
        Node *res;
        Node *first=head1;
        Node *second=head2;
  Node *ptr;
  res=NULL;
  
  int sum=0,c=0;
while(first|| second){
    
    int data1=0;
    int data2=0;
    
    if(first) data1=first->val;
    if(second) data2= second->val;
    int sum=data1 + data2+c;
    if(sum>9)
      {
          sum=sum%10;
          c=1;
      }
      else
      c=0; 
    Node* nn = new Node(sum);
     if(!res)
      res=ptr=nn;
      else{
          ptr->next=nn;
          ptr=ptr->next;
           
      }
     
    if(first)first=first->next;
    if(second) second=second->next;
    
}
if(c==1)
  {
      Node* nn = new Node(1);
     ptr->next=nn;
  }

  return res;
  
        
	
};
};

int main(){
	int n,m;
	cin >> n >> m;
	Node *head1=NULL;
    Node *head2=NULL;
	Solution A;
	for(int i=0;i<n;i++){
		int in;
		cin >> in;
		head1=A.insert(head1,in);
		
	}
	 for(int i=0;i<m;i++){
		int in;
		cin >> in;
		head2=A.insert(head2,in);
		
	}

	//A.display(head);
	Node *result=NULL;
	result=A.addLists(head1,head2,n,m);
	A.display(result);

	
}