#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node *left;
Node *right;
Node (int d){
    this->data=d;
    left=right=nullptr;
}
};

class Solution{
  public:
  void Inorder(Node *root){
     if(root){
       Inorder(root->left);
       cout << root->data << " ";
       Inorder(root->right);
     }
  }
     void Preorder(Node *root){
     if(root){
     
       cout << root->data << " ";
         Preorder(root->left);
       Preorder(root->right);
     }
 

  }
   void Postorder(Node *root){
     if(root){
         Postorder(root->left);
       Postorder(root->right);
        cout << root->data << " ";
     }
 

  }
  
};
int main(){
Node*root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->left->right->left=new Node(7);
root->right->right=new Node(6);
 Solution MyTree; 
 cout << "Inorder :" ;
 MyTree.Inorder(root);
 cout << "\n";
 cout << "Preorder :" ;
 MyTree.Preorder(root);
  cout << "\n";
  cout << "Postorder :" ;
 MyTree.Postorder(root);

}