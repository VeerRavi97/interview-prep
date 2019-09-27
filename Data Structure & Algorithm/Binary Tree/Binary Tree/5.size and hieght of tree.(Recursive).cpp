#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
  Node(int d){
    this->data=data;
    left=right=nullptr;
  }

};
class Solution {
    public:
int size(Node *root){
   if(!root){
       return 0;
   }
 return 1+size(root->left)+size(root->right);

}
int height(Node *root){
  if(!root) return -1;
  return 1+max(height(root->left),height(root->right));
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
 int size=MyTree.size(root);
cout << size << "\n";
int height=MyTree.height(root);
cout << height << "\n";


}