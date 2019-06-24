#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node *left, *right;
 Node(int d){
     this->data=d;
     this->left=this->right=nullptr;
 }
};
class Solution{

public:
void MorisInorderTraversal(Node *root){
  Node *current=root;
  while(current){
   if(!current->left){
       cout << current->data << " ";
       current=current->right;
   }else{
     Node *predecessor=current->left;
     while(predecessor->right &&predecessor->right!=current)
      predecessor=predecessor->right;
      if(!predecessor->right){
          predecessor->right=current;
          current=current->left;
      }
      else if(predecessor->right==current){
           predecessor->right=nullptr;
           cout << current->data << " ";
           current=current->right;
      }
      else{};

   }
  }

}
void MorisPreorderTraversal(Node *root){
  Node *current=root;
  while(current){
   if(!current->left){
       cout << current->data << " ";
       current=current->right;
   }else{
     Node *predecessor=current->left;
     while(predecessor->right &&predecessor->right!=current)
      predecessor=predecessor->right;
      if(!predecessor->right){
          cout << current->data << " ";
          predecessor->right=current;
          current=current->left;
      }
      else if(predecessor->right==current){
           predecessor->right=nullptr;
           
           current=current->right;
      }
      else{};

   }

 

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
 MyTree.MorisInorderTraversal(root);
 cout << "\n";
 cout << "Preorder :" ;
 MyTree.MorisPreorderTraversal(root);
  cout << "\n";
//   cout << "Postorder :" ;
//  MyTree.Postorder(root);
}