#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *left,*right;
  Node(int d){
      this->data=d;
      this->left=this->right=nullptr;
  }

};
  
class Solution{

 public:
  int haspathsum(Node *root,vector<int>&output,int sum){
    //   cout << sum << "\n";
     if(root->data==sum && !root->left && !root->right){
        //  cout << "equal " << sum << "\n";
      output.push_back(root->data);
      return 1;
     }
     int ans=0;
     if(root->left)
     ans=ans||haspathsum(root->left,output,sum-root->data);
     if(root->right)
     ans=ans||haspathsum(root->right,output,sum-root->data);
     if(ans) output.push_back(root->data);
     return ans;
   
  }

 void Preorder(Node *root){
     if(root){
     
       cout << root->data << " ";
         Preorder(root->left);
       Preorder(root->right);
     }
 }


};
int main(){

   Solution Mytree;
   Node *root=new Node(10);
   root->left=new Node(8);
   root->right=new Node(7);
   root->left->left=new Node(3);
   root->left->right=new Node(5);
   root->right->left=new Node(2);
  int sum;
  cin >> sum;

   vector<int>output;

//    Mytree.Preorder(root);
   int ans=Mytree.haspathsum(root,output,sum);
   if(ans){
   for(auto x:output){
    cout << x << " ";

   }
   }
    return 0;
}