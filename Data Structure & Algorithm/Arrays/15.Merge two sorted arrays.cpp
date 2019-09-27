#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&A,vector<int>&B){
int m=A.size();
int n=B.size();
for(int i=n-1;i>=0;i--){
if(B[i]<A[m-1]){ // if element can be transferred from B to A
int popped=A[m-1];
int j=m-2;
while(j>=0&&A[j]>B[i]){
    A[j+1]=A[j];
    j--;
}
A[j+1]=B[i];
B[i]=popped;

}

}


}



int main(){
 
 vector<int>A={5,6,7,8,9};
 vector<int>B={1,2,3,5};
 merge(A,B);
 for(auto x:A){
     cout << x << " ";
 }
 cout << endl;
 for(auto x:B){
     cout << x << " ";
 }
return 0;
}